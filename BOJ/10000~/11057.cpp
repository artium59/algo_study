#include <stdio.h>

int n, ans=0, dp[1001][10];

int main() {
    for (int i = 0; i < 10; i++)
        dp[1][i] = 1;
    
    for (int i = 0; i < 10; i++) {
        for (int j = 2; j < 1001; j++) {
            for (int k = 0; k <= i; k++)
                dp[j][i] += dp[j-1][k]%10007;
        }
    }

    scanf("%d", &n);
    for (int i = 0; i < 10; i++)
        ans += dp[n][i]%10007;
    
    printf("%d", ans%10007);
    
    return 0;
}
