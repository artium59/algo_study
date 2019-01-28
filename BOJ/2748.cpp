#include <iostream>

int main() {
    int n;
    long long fibonacci[90];

    scanf("%d", &n);

    fibonacci[0] = 0; fibonacci[1] = 1;
    for (int i = 2; i <= n; i++)
        fibonacci[i] = fibonacci[i-2] + fibonacci[i-1];

    printf("%lld", fibonacci[n]);

    return 0;
}
