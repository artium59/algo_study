#include <bits/stdc++.h>

int main() {
    int n;
    scanf("%d", &n);
    
    while (1) {
        for (int i = n; i > 0; i--)
            printf("*");
        
        if (n == 0) break;
        printf("\n");
        n--;
    }
    
    return 0;
}