#include <bits/stdc++.h>

int main() {
    long long n, t, ans, arr = 0;
    scanf("%lld", &n);
    
    ans = n * (n-1) / 2;
    
    while (n--) {
        scanf("%lld", &t);
        arr += t;
    }
    
    printf("%lld", arr - ans);
    
    return 0;
}