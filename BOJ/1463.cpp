#include <bits/stdc++.h>

int main() {
    int n;
    scanf("%d", &n);
    int dp[n+1];
    
    dp[1] = 0; dp[2] = dp[3] = 1;
    for (int i = 4; i <= n; i++) {
        int t = dp[i-1] + 1;
        dp[i] = dp[i-1] + 1;
        
        if (i%2 == 0) {
            if (i%3 == 0)
                t = std::min(dp[i/2], dp[i/3]) + 1;
            else
                t = dp[i/2] + 1;
        }
        else if (i%3 == 0)
            t = dp[i/3] + 1;
            
        dp[i] = std::min(t, dp[i]);
    }
    
    printf("%d", dp[n]);
    
    return 0;
}