#include <bits/stdc++.h>

int main() {
    int m, count = 0;
    int c[6] = {500, 100, 50, 10, 5, 1};
    
    scanf("%d", &m);
    m = 1000 - m;
    
    for (int i = 0; i < 6; i++) {
        count += (m / c[i]);
        m %= c[i];
    }
    
    printf("%d", count);
    
    return 0;
}