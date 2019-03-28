#include <bits/stdc++.h>

int main() {
    int a, b, c, x, y;
    scanf("%d %d %d", &a, &b, &c);
    
    x = c / 60;
    y = c % 60;
    
    printf("%d %d", (a+x+(b+y)/60)%24, (b+y)%60);
    
    return 0;
}