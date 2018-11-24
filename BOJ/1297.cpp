#include <bits/stdc++.h>

int main() {
    double a, b, c, rate;
    scanf("%lf %lf %lf", &a, &b, &c);
    rate = a/sqrt(b*b+c*c);
    
    printf("%d %d", (int)(b*rate), (int)(c*rate));
    return 0;
}