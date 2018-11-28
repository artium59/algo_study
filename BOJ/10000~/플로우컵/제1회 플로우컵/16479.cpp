#include <bits/stdc++.h>

int main() {
    float k, d1, d2;
    scanf("%f %f %f", &k, &d1, &d2);
    
    printf("%f", k*k - (d1-d2)*(d1-d2)/4);
    return 0;
}