#include <cstdio>

inline int min(int a, int b) { return a < b ? a : b; }

int n, x, arr[200], dp[200][200];

int main() {
    scanf("%d %d", &n, &x);
    for (int i = 0; i < n; ++i) scanf("%d", arr+i);

    for (int i = n-2; i >= 0; --i) {
        for (int j = i+1; j < n; ++j) {
            dp[i][j] = (j-i == 1) ? arr[i] != arr[j] : 1e9;

            for (int k = i; k < j; ++k) {
                x = dp[i][k] + dp[k+1][j] + (arr[i] != arr[k+1]);
                dp[i][j] = min(dp[i][j], x);
            }
        }
    }
    printf("%d", dp[0][n-1]);

    return 0;
}
