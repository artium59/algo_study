#include <cstdio>

int main() {
    int n, ans=1e9, b, arr[50];

    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", arr+i);

    if (n > 2) {
        for (int a = 0; a < 501; a++) {
            b = arr[1] - arr[0]*a;

            for (int i = 2; i < n; i++) {
                if (arr[i] != arr[i-1]*a + b) break;
                if (i == n-1) ans = arr[i]*a + b;
            }
        }

        for (int a = -1; a > -501; a--) {
            b = arr[1] - arr[0]*a;

            for (int i = 2; i < n; i++) {
                if (arr[i] != arr[i-1]*a + b) break;
                if (i == n-1) ans = arr[i]*a + b;
            }
        }
    }

    if (ans == 1e9) {
        if (n == 1) printf("A");
        else if (n == 2) {
            if (arr[0] == arr[1]) printf("%d", arr[1]);
            else printf("A");
        }
        else printf("B");
    }
    else printf("%d", ans);

    return 0;
}
