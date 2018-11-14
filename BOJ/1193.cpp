#include <bits/stdc++.h>

int main() {
    int x, i;
    scanf("%d", &x);
    
    for (i = 1; i < 5000; i++) {
        x -= i;
        if (x <= 0) {
            x += i;
            break;
        }
    }
    
    if (i % 2 == 1) {
        printf("%d/%d", i-x+1, x);
    }
    else {
        printf("%d/%d", x, i-x+1);
    }
    
    return 0;
}