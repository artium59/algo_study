#include <cstdio>

inline int min(int a, int b) { return a < b ? a : b; }

int main() {
    int n, arr[1001];

    arr[0] = 0;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", arr+i);
    
    for (int i = 2; i <= n; i++) {
        for (int j = 0; j <= i-j; j++)
            arr[i] = min(arr[i], arr[i-j]+arr[j]);
    }

    printf("%d", arr[n]);
    return 0;
}
