#include <iostream>
#include <cstring>

const int xrr[4] = { 1, -1, 0, 0 }, yrr[4] = { 0, 0, 1, -1 };
int max(int a, int b) {
    return a > b ? a : b;
}

int n, map[500][500], dp[500][500];

int DFS(int y, int x) {
    int& ret = dp[y][x];
    if (ret != 0) return ret;
    int ny, nx;

    for (int i = 0; i < 4; i++) {
        ny = y+yrr[i]; nx = x+xrr[i];
        if (-1 < ny && ny < n && -1 < nx && nx < n && map[y][x] < map[ny][nx])
        ret = max(ret, DFS(ny, nx)+1);
    }

    return ret;
}

int main() {
    int ans = 0;

    memset(dp, 0, sizeof(dp));

    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            scanf("%d", &map[i][j]);
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            ans = max(ans, DFS(i, j));
    }

    printf("%d", ans+1);

    return 0;
}