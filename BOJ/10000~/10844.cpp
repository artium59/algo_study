#include <iostream>

const int MAX = 1000000000;
int dp[100][10];

void Init() {
    for (int i = 1; i < 10; i++)
        dp[0][i] = 1;
}

int main() {
    int n, ans = 0;

    scanf("%d", &n);

    Init();
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < 10; j++) {
            if (j == 0) dp[i][j] = dp[i-1][j+1];
            else if (j == 9) dp[i][j] = dp[i-1][j-1];
            else dp[i][j] = (dp[i-1][j-1] + dp[i-1][j+1]) % MAX;
        }
    }

    for (int i = 0; i < 10; i++)
        ans = (ans + dp[n-1][i]) % MAX;

    printf("%d", ans);

    return 0;
}
