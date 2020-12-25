#include <cstdio>

const int MAX = 1e9;
int n, ans=MAX, h[1000][3], dp[1000][3];

inline int min(int a, int b) { return a < b ? a : b; }

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
        scanf("%d %d %d", &h[i][0], &h[i][1], &h[i][2]);

    for (int k = 0; k < 3; ++k) {
        for (int j = 0; j < 3; ++j) {
            if (j == k) dp[0][j] = h[0][j];
            else dp[0][j] = MAX;
        }

        for (int i = 1; i < n; ++i) {
            dp[i][0] = min(dp[i-1][1], dp[i-1][2]) + h[i][0];
            dp[i][1] = min(dp[i-1][0], dp[i-1][2]) + h[i][1];
            dp[i][2] = min(dp[i-1][0], dp[i-1][1]) + h[i][2];
        }

        for (int j = 0; j < 3; ++j) {
            if (k != j) ans = min(ans, dp[n-1][j]);
        }
    }

    printf("%d", ans);
    return 0;
}
