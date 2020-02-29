#include <cstdio>
using ll = long long;

int main() {
    int tc;
    ll n, m;

    scanf("%d", &tc);
    for (int i = 1; i <= tc; i++) {
        scanf("%lld %lld", &n, &m);
        if ((m+n) % 2 == 0)
            n = (m+n)/2LL * (m-n+1);
        else
            n = (m+n) * ((m-n+1)/2LL);
        printf("Scenario #%d:\n%lld\n\n", i, n);
    }

    return 0;
}
