#include <bits/stdc++.h>

int main() {
    float a, b, c;
    scanf("%f %f %f", &a, &b, &c);
    printf("%f", (a*b*c)/(a*b+b*c+c*a));

    return 0;
}