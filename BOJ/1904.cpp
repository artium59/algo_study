#include <cstdio>

int n, arr[1000001];

int main() {
    arr[1] = 1; arr[2] = 2;
    for (int i = 3; i < 1000001; i++) arr[i] = (arr[i-1] + arr[i-2])%15746;
    scanf("%d", &n);
    printf("%d", arr[n]);

    return 0;
}
