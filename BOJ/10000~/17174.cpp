#include <iostream>

int main() {
    int n, m, a;

    scanf("%d %d", &n, &m);
    a = n;

    while (n / m) {
        a += n/m;
        n /= m;
    }

    printf("%d",a);

    return 0;
}