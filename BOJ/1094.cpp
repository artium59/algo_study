#include <bits/stdc++.h>

int main() {
    int x, ans = 0, a = 64;
    scanf("%d", &x);
    
    if (x == 64)
        ans = 1;
    else {
        while (x != 0) {
            a /= 2;
            
            if (x - a >= 0) {
                x -= a;
                ans++;
            }
        }
    }
    
    printf("%d", ans);
    
    return 0;
}