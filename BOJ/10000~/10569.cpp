#include <bits/stdc++.h>

int main() {
    int t, v, e;
    scanf("%d", &t);
    
    for (int i = 0; i < t; i++) {
        scanf("%d %d", &v, &e);
        printf("%d\n", 2-v+e);
    }
    
    return 0;
}