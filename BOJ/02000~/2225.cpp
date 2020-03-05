#include <cstdio>

const long long MAX = 1000000000;
int n, k;
long long dp[201][201];

int main() {
    scanf("%d %d", &n, &k);
    for (int i = 0; i < 201; i++) {
        dp[i][1] = 1;
        dp[0][i] = 1;
    }
    dp[0][0] = 0;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= k; j++) {
            for (int a = i; a >= 0; a--)
                dp[i][j] = (dp[i][j] + dp[a][j-1]) % MAX;
        }
    }

    printf("%lld", dp[n][k]);

    return 0;
}
