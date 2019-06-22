#include <iostream>

int t, n, m, dp[30][30];
int main() {
    for (int i = 1; i < 30; i++) {
        dp[i][1] = i;
        for (int j = 2; j <= i; j++)
            dp[i][j] = dp[i][j-1] * (i-j+1) / j;
    }

    scanf("%d", &t);
    while(t--) {
        scanf("%d %d", &n, &m);
        printf("%d\n", dp[m][n]);
    }

    return 0;
}
