#include <bits/stdc++.h>

int main() {
    int ans = 0;
    char c;
    
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            std::cin >> c;
            if (c == 'F' && (i+j) % 2 == 0)
                ans++;
        }
    }
    
    printf("%d", ans);
    
    return 0;
}