#include <bits/stdc++.h>

int main() {
    int t, k;
    scanf("%d", &t);
    
    for (int i = 0; i < t; i++) {
        scanf("%d", &k);
        printf("%d\n", (int)(pow(2,k)-1));
    }
    
    return 0;
}