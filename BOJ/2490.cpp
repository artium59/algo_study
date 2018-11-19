#include <bits/stdc++.h>

int main() {
    int t;
    
    for (int i = 0; i < 3; i++) {
        int ans = 0;
        
        for (int j = 0; j < 4; j++) {    
            scanf("%d", &t);
            ans += t;
        }
        
        if (ans == 0)
            printf("D\n");
        else if (ans == 1)
            printf("C\n");
        else if (ans == 2)
            printf("B\n");
        else if (ans == 3)
            printf("A\n");
        else
            printf("E\n");
    }
    
    return 0;
}