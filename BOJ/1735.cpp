#include <iostream>

int GCD(int a, int b) {
    if (b == 0) return a;
    else return GCD(b, a % b);
}

int main() {
    int a, b, x, y, upAns, downAns, gcd;
    scanf("%d %d %d %d", &a, &b, &x, &y);
    
    upAns = a * y + b * x;
    downAns = b * y;
    gcd = GCD(upAns, downAns);
    
    printf("%d %d", upAns / gcd, downAns / gcd);
        
    return 0;
}
