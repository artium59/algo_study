#include <bits/stdc++.h>

int main() {
    int n, ans = 2;
    scanf("%d", &n);
    
    for (int i = 0; i < n; i++)
        ans += 1 << i;
    
    printf("%d", ans * ans);
    return 0;
}