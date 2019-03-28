#include <iostream>

int wine[10001], dp[10001][3];

int max(int a, int b) {
    return a > b ? a : b;
}

int max(int a, int b, int c) {
    return max(a, max(b, c));
}

int main() {
    int n;

    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", &wine[i]);

    wine[0] = dp[0][0] = dp[0][1] = dp[0][2] = 0;
    dp[1][0] = 0; dp[1][1] = dp[1][2] = wine[1];
    for (int i = 2; i <= n; i++) {
        dp[i][0] = max(dp[i-1][0], dp[i-1][1], dp[i-1][2]);
        dp[i][1] = max(dp[i-2][0] + wine[i-1], dp[i-1][0] + wine[i]);
        dp[i][2] = dp[i-2][0] + wine[i-1] + wine[i];
    }

    printf("%d", max(dp[n][0], max(dp[n][1], dp[n][2])));

    return 0;
}
