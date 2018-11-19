#include <bits/stdc++.h>

int main() {
    int x, y, ans = 0, sum = 0;
    
    for (int i = 0; i < 4; i++) {
        scanf("%d %d", &x, &y);
        
        sum = sum + y - x;
        
        if (sum > ans)
            ans = sum;
    }
    
    printf("%d", ans);
    
    return 0;
}