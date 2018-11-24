#define M_PI 3.14159265358979323846

#include <bits/stdc++.h>

int main() {
    int n;
    scanf("%d", &n);
    
    printf("%6f\n%6f", n*n*M_PI, (double)(n*n*2));
    
    return 0;
}