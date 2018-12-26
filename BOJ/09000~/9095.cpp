#include <bits/stdc++.h>

int main() {
    int t, n, dp[10];
    scanf("%d", &t);
    
    dp[0] = 1; dp[1] = 2; dp[2] = 4;
    for (int h = 3; h < 10; h++)
        dp[h] = dp[h-1] + dp[h-2] + dp[h-3];
    
    for (int i = 0; i < t; i++) {
        scanf("%d", &n);
        printf("%d\n", dp[n-1]);
    }
    
    return 0;
}