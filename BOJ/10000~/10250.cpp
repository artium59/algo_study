#include <bits/stdc++.h>

int main() {
    int t, h, w, n, i, ans;
    scanf("%d", &t);
    
    for (int a = 0; a < t; a++) {
        scanf("%d %d %d", &h, &w, &n);

        for (i = 1; i < w+1; i++) {
            if (n <= h)
                break;
            n -= h;
        }
        
        printf("%d\n", 100*n+i);    
    }
    
    return 0;
}