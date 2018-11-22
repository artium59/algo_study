#include <bits/stdc++.h>

int main() {
    // 1 ≤ K ≤ 1,000,000
    int k, ans = 1, split = 0;
    scanf("%d", &k);
    
    while (k > ans)
        ans = ans << 1;
    
    printf("%d ", ans);
    
    while (ans > 0) {
        if (k == ans) break;
        
        ans = ans >> 1;
        split++;
        if (k > ans)
            k -= ans;
    }
    
    printf("%d", split);
    
    return 0;
}