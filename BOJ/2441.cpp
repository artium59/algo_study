#include <bits/stdc++.h>

int main() {
    int n, j = 0;
    scanf("%d", &n);
    
    while (1) {
        for (int i = 0; i < j; i++)
            printf(" ");
        
        for (int i = 0; i < n-j; i++)
            printf("*");
        
        printf("\n");
        j++;
        
        if (j == n+1) break;
    }
    
    return 0;
}