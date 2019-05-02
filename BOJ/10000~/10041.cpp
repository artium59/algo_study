#include <bits/stdc++.h>

int main() {
    int w, h, n, x, y, a, b, ans = 0;

    scanf("%d %d %d %d %d", &w, &h, &n, &x, &y);

    for (int i = 0; i < n-1; i++) {
        scanf("%d %d", &a, &b);
        ans += (a-x)*(b-y) > 0 ? std::max(abs(a-x), abs(b-y)) : abs(a-x)+abs(b-y);
        x = a; y = b;
    }

    printf("%d", ans);

    return 0;
}
