#include <bits/stdc++.h>

int main() {
    int t;
    scanf("%d", &t);
    
    for (int i = 0; i < t; i++) {
        int y = 0, k = 0, a, b;
        
        for (int j = 0; j < 9; j++) {
            scanf("%d %d", &a, &b);
            y += a; k += b;
        }
        
        if (y > k) printf("Yonsei\n");
        else if (y < k) printf("Korea\n");
        else printf("Draw\n");
    }
    
    return 0;
}