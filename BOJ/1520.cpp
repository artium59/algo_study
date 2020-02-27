#include <cstdio>
#include <functional>
using namespace std;

const int xrr[] {0,0,-1,1}, yrr[] {-1,1,0,0};
int m, n, dx, dy, grid[500][500], dp[500][500];

int main() {
    scanf("%d %d", &m, &n);
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            scanf("%d", &grid[i][j]);
            dp[i][j] = -1;
        }
    }
    dp[m-1][n-1] = 1;

    function<bool(int, int)> boundary_check = [](int y, int x) {
        return (0<=y&&y<m && 0<=x&&x<n);
    };

    function<int(int, int)> dfs = [&](int y, int x) {
        if (dp[y][x] != -1) return dp[y][x];
        dp[y][x] = 0;

        for (int i = 0; i < 4; ++i) {
            dy = y + yrr[i];
            dx = x + xrr[i];

            if (boundary_check(dy, dx) && grid[y][x] > grid[dy][dx])
                dp[y][x] += dfs(dy, dx);
        }

        return dp[y][x];
    };

    printf("%d", dfs(0, 0));
    return 0;
}
