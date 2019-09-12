#include <cstdio>

const int MAX = 1000000;
// late, day, absent
int n, ans, dp[2][1002][3];

int main() {
    dp[0][1][0] = dp[0][1][1] = dp[1][1][0] = 1;
    
    for (int i = 2; i < 1002; i++) {
        for (int l = 0; l < 2; l++) {
            for (int j = 0; j < 3; j++)
                dp[l][i][0] += dp[l][i-1][j]%MAX;
            
            dp[l][i][1] = dp[l][i-1][0]%MAX;
            dp[l][i][2] = dp[l][i-1][1]%MAX;
        }
        
        for (int j = 0; j < 3; j++)
            dp[1][i][0] += dp[0][i-1][j]%MAX;
    }
    
    scanf("%d", &n);
    for (int j = 0; j < 3; j++)
        ans += (dp[0][n][j] + dp[1][n][j])%MAX;
    printf("%d", ans%MAX);

    return 0;
}
