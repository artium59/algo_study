#include <bits/stdc++.h>

int main() {
    int t, n;
    long long k[68];
    scanf("%d", &t);
    
    for (int h = 0; h < 68; h++) {
        if (h < 2)
            k[h] = 1;
        else if (h == 2)
            k[h] = 2;
        else if (h == 3)
            k[h] = 4;
        else
            k[h] = k[h-1] + k[h-2] + k[h-3] + k[h-4];
    }
    
    for (int i = 0; i < t; i++) {
        scanf("%d", &n);
        printf("%lld\n", k[n]);
    }
    
    return 0;
}