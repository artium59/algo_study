#include <bits/stdc++.h>

int main() {
    int n, ans;
    scanf("%d", &n);
    
    if (n != 4 && n != 7)
        ans = n/5 + ((n%5 != 0) ? ((n%5%2 != 0) ? 1 : 2) : 0);
    else
        ans = -1;
    
    printf("%d", ans);
    return 0;
}