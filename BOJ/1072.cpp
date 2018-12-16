#include <bits/stdc++.h>

int main() {
    long long x, y, z ,ans;
    scanf("%lld %lld", &x, &y);
    
    z = floor(y * 100 / x);
    
    if (z > 98)
        ans = -1;
    else
        ans = ceil(((double)(z+1)*x - 100*y)/(99-z));
    
    printf("%lld %lld", z, ans);
    
    return 0;
}