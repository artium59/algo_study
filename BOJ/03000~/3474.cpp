#include <bits/stdc++.h>

int main() {
    int t, n;
    scanf("%d", &t);
    
    for (int i = 0; i < t; i++) {
        int ans = 0;
        scanf("%d", &n);
        
        for (int j = 1; ;j++) {
            if (n >= (int)pow(5, j))
                ans += n/(int)pow(5, j);
            else
                break;
        }
        
        printf("%d\n", ans);
    }
    
    return 0;
}