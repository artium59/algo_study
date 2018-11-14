#include <bits/stdc++.h>

int main() {
    int r, b, i, t;
    scanf("%d %d", &r, &b);
    
    for (i = 1; ; i++) {
        t = b/i;
        if (t * i == b) {
            if ((t+2) * (i+2) == (r+b))
                break;
        }
    }
    
    printf("%d %d", std::max(t, i) + 2, std::min(t, i) + 2);
    
    return 0;
}