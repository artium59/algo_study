#include <iostream>

int n, ans = 0, arr[100];

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    for (int i = n-1; i > 0; i--) {
        if (arr[i] <= arr[i-1]) {
            ans += (arr[i-1]-arr[i]+1);
            arr[i-1] = arr[i]-1;
        }
    }

    printf("%d", ans);

    return 0;
}
