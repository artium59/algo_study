#include <bits/stdc++.h>

int main() {
    int a, b, c, d, e, ans;
    scanf("%d %d %d %d %d", &a, &b, &c, &d, &e);
    
    ans = (a*a + b*b + c*c + d*d + e*e)%10;
    
    printf("%d", ans);
    
    return 0;
}