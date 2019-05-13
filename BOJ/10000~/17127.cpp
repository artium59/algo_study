#include <iostream>

inline int max(int a, int b) { return a > b ? a : b; }

int n, ans = 0, arr[10];

void Find(int cur, int sum, int multi, int divide) {
    if (cur >= n) {
        if (divide == 3) ans = max(ans, sum+multi);
        return;
    }

    if (divide < 3) Find(cur+1, sum+multi, arr[cur], divide+1);
    Find(cur+1, sum, multi*arr[cur], divide);
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    Find(1, 0, arr[0], 0);

    printf("%d", ans);

    return 0;
}
