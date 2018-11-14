#include <bits/stdc++.h>

int main() {
    int n, t, ans = 0;
    scanf("%d", &n);
    
    for (int i = 0; i < n; i++) {
        scanf("%d", &t);
        ans += t;
    }
    
    printf("%d", ans - n + 1);
    
    return 0;
}