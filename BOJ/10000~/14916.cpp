#include <cstdio>

int main() {
    int n, ans;
    scanf("%d", &n);

    if (n == 1 || n == 3) ans = -1;
    else {
        ans = n/5; n %= 5;
        if (n%2) ans += (n+5)/2 - 1;
        else ans += n/2;
    }

    printf("%d", ans);

    return 0;
}
