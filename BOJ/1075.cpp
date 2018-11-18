#include <bits/stdc++.h>

int main() {
    int n, f;
    
    scanf("%d %d", &n, &f);
    
    n = f - ((n/100) * 100 % f);
    
    printf("%02d", n == f ? 0 : n);
    
    return 0;
}