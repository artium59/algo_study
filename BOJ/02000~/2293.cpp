#include <cstdio>
#include <algorithm>

int n, k, arr[100], dp[10001];

int main() {
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; i++) scanf("%d", arr+i);

    std::sort(arr, arr+n);
    dp[0] = 1;

    for (int j = 0; j < n; j++) {
        for (int i = arr[j]; i <= k; i++) {
            if (i-arr[j] < 0) break;

            dp[i] += dp[i-arr[j]];
        }
    }

    printf("%d", dp[k]);

    return 0;
}
