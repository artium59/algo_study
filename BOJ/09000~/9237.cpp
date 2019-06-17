#include <iostream>
#include <algorithm>

int n, ans = 0, t[100000];

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &t[i]);

    std::sort(t, t+n, std::greater<int>());

    for (int i = 0; i < n; i++) {
        if (t[i]+i > ans) ans = t[i] + i;
    }

    printf("%d", ans+2);

    return 0;
}
