#include <bits/stdc++.h>

int main() {
    int a, t;
    scanf("%d %d", &a, &t);
    printf("%d", (int)floor(a*a - t*t + 0.5));

    return 0;
}