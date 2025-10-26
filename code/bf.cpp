// solving tsp problem using brute force
#include <stdio.h>
#define N 101

int n, s, a[N][N], visited[N], ans = 1e9;

void dfs(int u, int cnt, int cost) {
    if (cnt == n && a[u][s]) {
        if (cost + a[u][s] < ans) {
            ans = cost + a[u][s];
        }
        return;
    }

    for (int v = 0; v < n; v++) {
        if (!visited[v]) {
            visited[v] = 1;
            dfs(v, cnt + 1, cost + a[u][v]);
            visited[v] = 0;
        }
    }
}

int main() {
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    scanf("%d%d", &n, &s);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    visited[s] = 1;
    dfs(s, 1, 0);

    printf("%d\n", ans);

    return 0;
}