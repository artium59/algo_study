#include <bits/stdc++.h>

int main() {
    int testCase;
    scanf("%d", &testCase);
    
    for (int i = 0; i < testCase; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        
        if (a % 10 != 0) {
            if (b % 4 != 0)
                printf("%d\n", (int)pow(a%10, b%4) % 10);
            else
                printf("%d\n", (int)pow(a%10, 4) % 10);
        }
        else
            printf("10\n");
    }
    
    return 0;
}