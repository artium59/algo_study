#include <bits/stdc++.h>

int main() {
    int t, n;
    long long padovan[100];
    scanf("%d", &t);
    
    for (int h = 0; h < 100; h++) {
        if (h < 3) padovan[h] = 1;
        else padovan[h] = padovan[h-2] + padovan[h-3];
    }
    
    for (int i = 0; i < t; i++) {
        scanf("%d", &n);
        printf("%lld\n", padovan[n-1]);
    }
    
    return 0;
}