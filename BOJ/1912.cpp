#include <iostream>

int arr[100001];

int max(int a, int b) {
    return a > b ? a : b;
}

int main() {
    int n, ans = -987654321;

    arr[0] = 0;

    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &arr[i]);
        arr[i] = max(arr[i-1]+arr[i], arr[i]);
        ans = max(ans, arr[i]);
    }

    printf("%d", ans);

    return 0;
}
