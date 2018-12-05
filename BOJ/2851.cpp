#include <bits/stdc++.h>

int main() {
    int n, ans = 0;
    bool isEat = true;
    
    for (int i = 0; i < 10; i++) {
        scanf("%d", &n);
        
        if (isEat) {
            if (ans + n <= 100)
                ans += n;
            else {
                if (abs(ans+n-100) <= abs(ans-100))
                    ans += n;
                isEat = false;
            }
        }
        
    }
    
    printf("%d", ans);
    
    return 0;
}