#include <bits/stdc++.h>

int main() {
    float a, b, c, m, t;
    scanf("%f %f %f %f", &a, &b, &c, &m);
    t = (a*a-c*c+b*b)/(2*b);
    printf("%f", a*a-t*t+(m-t)*(m-t));
    return 0;
}