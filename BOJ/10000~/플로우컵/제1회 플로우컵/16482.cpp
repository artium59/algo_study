#include <cstdio>

// Ceva's theorem
int main() {
    float a, b, c, m, n, t;
    scanf("%f %f %f %f %f", &a, &b, &c, &m, &n);
    t = (a - n) * (c - m);
    printf("%f", (b*t)/(t+m*n));
    return 0;
}