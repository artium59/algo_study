#include <iostream>

int main() {
    long long n, t, ans = 0, cur = 2, next;

    scanf("%lld", &n);

    ans += n;
    while (cur < n) {
        t = n/cur + (n%cur == 0 ? 0 : 1);
        if (t == 1) next = n;
        else next = n/(t-1) + (n%(t-1) == 0 ? 0 : 1);

        ans += (next-cur) * t;
        cur = next;
    }
	
    if (n == 1) printf("1");
    else printf("%lld", ans + 1);

    return 0;
}
