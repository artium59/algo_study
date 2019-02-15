#include <stdio.h>

const int MAX = 1000000009;

long long dp[1000001];

int main() {
    int t, n;
    scanf("%d", &t);
    
    dp[1] = 1; dp[2] = 2; dp[3] = 4;
    for (int i = 4; i < 1000001; i++)
        dp[i] = (dp[i-1] + dp[i-2] + dp[i-3]) % MAX;
    
    for (int i = 0; i < t; i++) {
        scanf("%d", &n);
        printf("%lld\n", dp[n]);
    }

    return 0;
}
