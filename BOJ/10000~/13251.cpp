#include <iostream>

double a=0.,s=0.,m,k,t,p[50];
int main() {
    scanf("%lf", &m);
    for (int i = 0; i < m; i++) {
        scanf("%lf", p+i);
        s += p[i];
    }
    scanf("%lf", &k);

    for (int i =0; i < m; i++) {
        if (p[i] < k) continue;

        t = 1.;
        for (int j = 0; j < k; j++) t*=(p[i]-j)/(s-j);
        a += t;
    }

    printf("%.9lf",a);
}
