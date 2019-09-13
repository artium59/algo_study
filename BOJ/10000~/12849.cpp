#include <cstdio>

const int MAX = 1000000007;
int d;
long long dp[100001][8];

int main() {
    dp[0][0] = 1;
    for (int i = 1; i < 100001; i++) {
        dp[i][0] = (dp[i-1][1] + dp[i-1][2]) % MAX;
        dp[i][1] = (dp[i-1][0] + dp[i-1][2] + dp[i-1][3]) % MAX;
        dp[i][2] = (dp[i-1][0] + dp[i-1][1] + dp[i-1][3] + dp[i-1][5]) % MAX;
        dp[i][3] = (dp[i-1][1] + dp[i-1][2] + dp[i-1][4] + dp[i-1][5]) % MAX;
        dp[i][4] = (dp[i-1][3] + dp[i-1][5] + dp[i-1][6]) % MAX;
        dp[i][5] = (dp[i-1][2] + dp[i-1][3] + dp[i-1][4] + dp[i-1][7]) % MAX;
        dp[i][6] = (dp[i-1][4] + dp[i-1][7]) % MAX;
        dp[i][7] = (dp[i-1][5] + dp[i-1][6]) % MAX;
    }
    
    scanf("%d", &d);
    printf("%lld", dp[d][0]);
    
    return 0;
}
