#include <iostream>

long long dp[90];

int main() {
    int n;

    scanf("%d", &n);

    dp[0] = 1; dp[1] = 1;
    for (int i = 2; i < 90; i++)
        dp[i] = dp[i-2] + dp[i-1];

    printf("%lld", dp[n-1]);

    return 0;
}
