#include <cstdio>

const long long MAX = 1000000009;
int t, a;
long long dp[100001][3];

int main() {
    dp[1][0] = 1;
    dp[2][1] = 1;
    dp[3][2] = 1;
    for (int i = 3; i < 100001; ++i) {
        dp[i][0] += (dp[i-1][1] + dp[i-1][2]) % MAX;
        dp[i][1] += (dp[i-2][0] + dp[i-2][2]) % MAX;
        dp[i][2] += (dp[i-3][0] + dp[i-3][1]) % MAX;
    }

    scanf("%d", &t);
    while (t--) {
        scanf("%d", &a);
        printf("%lld\n", (dp[a][0]+dp[a][1]+dp[a][2]) % MAX);
    }

    return 0;
}
