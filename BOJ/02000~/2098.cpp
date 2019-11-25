#include <cstdio>

const int MAX = 1e9;
int n, w[16][16], dp[16][1<<16];

inline int min(int a, int b) { return a < b ? a : b; }

int TSP(int cur, int visited) {
    if (visited == (1<<n)-1) return w[cur][0] == 0 ? MAX : w[cur][0];

    int& ret = dp[cur][visited];
    if (ret != 0) return ret;
    ret = MAX;

    for (int i = 0; i < n; ++i) {
        if ((1<<i & visited) || w[cur][i] == 0) continue;

        ret = min(ret, w[cur][i]+TSP(i, visited | 1<<i));
    }

    return ret;
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j)
            scanf("%d", &w[i][j]);
    }

    printf("%d", TSP(0, 1));

    return 0;
}
