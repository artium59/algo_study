#include <iostream>

int main() {
    int n, m, k, ans = 0;

    scanf("%d %d %d", &n, &m, &k);

    while (n >= 0 && m >= 0) {
        if (n+m < k) break;
        n -= 2; m -= 1; ans++;
    }

    printf("%d", ans-1);

    return 0;
}
