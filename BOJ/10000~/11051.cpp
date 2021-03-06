#include <stdio.h>

int n, k, dp[1001][1001];

int main() {
    for (int i = 0; i < 1001; i++) {
        for (int j = 1; j < i; j++)
            dp[i][j] = (dp[i-1][j-1] + dp[i-1][j]) % 10007;
        
        dp[i][0] = dp[i][i] = 1;
    }

    scanf("%d %d", &n, &k);
    printf("%d", dp[n][k]);

    return 0;
}
