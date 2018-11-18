#include <bits/stdc++.h>

int main() {
    int x, y, w, h, ans;
    scanf("%d %d %d %d", &x, &y, &w, &h);
    
    ans = std::min(std::min(w-x, x), std::min(h-y,y));
    
    printf("%d", ans);
    
    return 0;
}