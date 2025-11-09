#include <time.h>
#include <random>
#include <stdio.h>
#define N 100

int n = 10, s, a[N][N];

int main() {
    freopen("in.txt", "w", stdout);
    srand(time(0));

    s = rand() % n;
    printf("%d %d\n", n, s);
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            a[i][j] = a[j][i] = rand() % 10 + 1;
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", a[i][j]);
        }
        puts("");
    }

    return 0;
}