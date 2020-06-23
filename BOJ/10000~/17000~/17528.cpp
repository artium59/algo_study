#include <iostream>
using namespace std;

int n, arr[251], brr[251], dp[251][62501], sum_b, ans=1e9;

int main(void) {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d %d", arr+i, brr+i);
        sum_b += brr[i];
    }

    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j <= 62500; ++j) {
            if (j < arr[i]) dp[i][j] = dp[i-1][j];
            else dp[i][j] = max(dp[i-1][j], dp[i-1][j-arr[i]]+brr[i]);

            ans = min(ans, max(j, sum_b - dp[i][j]));
        }
    }

    printf("%d", ans);
    return 0;
}
