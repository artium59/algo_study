#include <iostream>

const int MAX = 1000000007;
int n, dp[51];

int main() {
    dp[0] = dp[1] = 1;
    for (int i = 2; i < 51; i++)
        dp[i] = (dp[i-1]+dp[i-2]+1)%MAX;

    scanf("%d", &n);
    printf("%d", dp[n]);

    return 0;
}
