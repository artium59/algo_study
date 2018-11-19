#include <bits/stdc++.h>

int main() {
    long long n, a = 0, i;
    scanf("%lld", &n);
    
    for (i = 0; i < 166666667; i++) {
        if (n <= 6 * (a += i) + 1)
            break;
    }
    
    printf("%lld", i+1);
    
    return 0;
}