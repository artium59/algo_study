#include <bits/stdc++.h>

int main() {
    int a, b, v, snail = 0, ans = 1;
    scanf("%d %d %d", &a, &b, &v);
    
    v -= a;
    ans += ceil((double)v/(double)(a-b));
    
    printf("%d", ans);
    
    return 0;
}