#include <iostream>

int main() {
    int a, b, n, w, x, y, cnt = 0;

    scanf("%d %d %d %d", &a, &b, &n, &w);

    for (int i = 1; i < n; i++) {
        if (a*i + b*(n-i) == w) {
            x = i; y = n-i; cnt++;
        }

        if (cnt > 1) break;
    }

    if (cnt == 1) printf("%d %d", x, y);
    else printf("-1");

    return 0;
}
