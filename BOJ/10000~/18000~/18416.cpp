#include <cstdio>

int n, s, e, ans, arr[100];

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) scanf("%d", arr+i);

    for (int i = 1; i < n; ++i) {
        if (arr[e] <= arr[i]) e = i;
        else s = e = i;

        ans = e-s+1 < ans ? ans : e-s+1;
    }
    if (n == 1) ans = 1;
    printf("%d", ans);

    return 0;
}
