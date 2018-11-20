#include <bits/stdc++.h>

int main() {
    long long a, b, t;
    scanf("%lld %lld", &a, &b);
    
    if (a > b) {
        t = a;
        a = b;
        b = t;
    }
    
    printf("%lld", ((b+a)*(b-a+1))/2);
    
    return 0;
}