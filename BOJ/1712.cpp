#include <cstdio>
using ll = long long;

int main() {
    ll a, b, c;
    scanf("%lld %lld %lld", &a, &b, &c);
    printf("%lld", c-b > 0 ? a/(c-b)+1 : -1);
    return 0;
}
