#include <iostream>

int main() {
    int n, f[21];
    scanf("%d", &n);

    f[0] = 0; f[1] = 1;
    for (int h = 2; h < n+1; h++)
        f[h] = f[h-1] + f[h-2];

    printf("%d", f[n]);

    return 0;
}
