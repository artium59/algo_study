#include <iostream>

inline int max(int a, int b) { return a > b ? a : b; }

int n, l, r, ans = 0, arr[1000];

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    l = r = arr[0];
    for (int i = 1; i < n; i++) {
        if (r < arr[i]) r = arr[i];
        else l = r = arr[i];

        ans = max(ans, r-l);
    }

    printf("%d", ans);

    return 0;
}
