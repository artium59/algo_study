#include <iostream>
#include <algorithm>

const int MAX = 1000000;
int n, b, c, arr[MAX];
long long ans = 0;

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    scanf("%d %d", &b, &c);

    std::for_each(arr, arr+n, [](const auto& a) {
        ans++;
        if (a-b > 0) ans += (a-b)/c;
        if ((a-b)%c > 0) ans++;
    });

    printf("%lld", ans);

    return 0;
}
