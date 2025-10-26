// solving tsp problem using simulated annealing
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define N 101
#define INF 1000000000

int n, start;
int dist[N][N];
int path[N];
int best_cost = INF;

int calc_cost(int *p) {
    int sum = 0;
    for (int i = 0; i < n - 1; i++)
        sum += dist[p[i]][p[i + 1]];
    sum += dist[p[n - 1]][p[0]];
    return sum;
}

void swap_random(int *p) {
    int i = rand() % (n - 1) + 1;
    int j = rand() % (n - 1) + 1;
    int tmp = p[i];
    p[i] = p[j];
    p[j] = tmp;
}

void simulated_annealing() {
    double T = 10000.0;
    double Tmin = 1e-4;
    double alpha = 0.995;
    int iter_per_T = 500;

    int current_cost = calc_cost(path);

    while (T > Tmin) {
        for (int i = 0; i < iter_per_T; i++) {
            int new_path[N];
            for (int k = 0; k < n; k++) new_path[k] = path[k];
            swap_random(new_path);

            int new_cost = calc_cost(new_path);
            int delta = new_cost - current_cost;

            if (delta < 0 || exp(-1.0 * delta / T) > (double)rand() / RAND_MAX) {
                for (int k = 0; k < n; k++) path[k] = new_path[k];
                current_cost = new_cost;
                if (current_cost < best_cost)
                    best_cost = current_cost;
            }
        }
        T *= alpha;
    }
}

int main() {
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    srand(time(NULL));
    scanf("%d%d", &n, &start);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &dist[i][j]);
        }
    }

    for (int i = 0; i < n; i++) path[i] = (start + i) % n;

    simulated_annealing();

    printf("%d\n", best_cost);
    return 0;
}