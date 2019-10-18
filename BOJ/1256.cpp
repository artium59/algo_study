#include <cstdio>
using ll = long long;

inline ll min(ll a, ll b) { return a < b ? a : b; }

const ll MAX = 1e10;
ll n, m, k, dp[101][101];

int main() {
    scanf("%lld %lld %lld", &n, &m, &k);

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (i == 1 || j == 1) dp[i][j] = (ll)(i+j);
            else dp[i][j] = min(dp[i-1][j] + dp[i][j-1], 2*MAX+1);
        }
    }

    if (dp[n][m] < k) { printf("-1"); return 0; }

    while (n && m) {
        if (dp[n][m] * n / (n+m) >= k) --n, printf("a");
        else k -= dp[n][m] * n / (n+m), --m, printf("z");
    }

    while (n--) printf("a");
    while (m--) printf("z");

    return 0;
}
