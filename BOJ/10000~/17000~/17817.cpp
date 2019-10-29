#include <cstdio>
using ll = long long;

int main() {
    ll q, l, r, ans, arr[10];

    arr[0] = 0;
    for (int i = 1; i < 10; ++i) arr[i] = arr[i-1]+i;

    scanf("%lld", &q);
    while (q--) {
        scanf("%lld %lld", &l, &r); --l;
        ans = (r/9-l/9) * 45 + arr[(int)(r%9)] - arr[(int)(l%9)];
        printf("%lld\n", ans);
    }

    return 0;
}
