#include <stdio.h>
#include <limits.h>

#define N 101
#define INF 1000000000

int n, s, dist[N][N], dp[1 << 20][N];

int min(int a, int b) {
    return a < b ? a : b;
}

int main() {
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    scanf("%d%d", &n, &s);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &dist[i][j]);
        }
    }

    for (int j = 0; j < (1 << n); j++) {
        for (int i = 0; i < n; i++) {
            dp[j][i] = INF;
        }
    }

    dp[1 << s][s] = 0;
    for (int j = 1; j < (1 << n); j++) {
        for (int u = 0; u < n; u++) {
            if (!(j & (1 << u))) continue;
            for (int v = 0; v < n; v++) {
                if (j & (1 << v)) continue;
                int next = j | (1 << v);
                dp[next][v] = min(dp[next][v], dp[j][u] + dist[u][v]);
            }
        }
    }

    int ans = INF;
    for (int i = 1; i < n; i++) {
        if (dist[i][0] == 0) continue;
        ans = min(ans, dp[(1 << n) - 1][i] + dist[i][s]);
    }

    printf("%d\n", ans);
    return 0;
}

