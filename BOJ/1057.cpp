#include <iostream>

int main() {
    int n, a, b, ans = 0;

    scanf("%d %d %d", &n, &a, &b);

    while (a != b) {
        if (a % 2 == 0) a = a/2;
        else a = a/2 + 1;

        if (b % 2 == 0) b = b/2;
        else b = b/2 + 1;

        ans++;
    }

    printf("%d", ans);

    return 0;
}