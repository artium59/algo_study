#include <bits/stdc++.h>

int main() {
    int i, j, ans = 0;
    char c, b[4][4], a[4][4] = {{'A', 'B', 'C', 'D'}, {'E', 'F', 'G', 'H'}, {'I', 'J', 'K', 'L'}, {'M', 'N', 'O', '.'}};
    
    for (i = 0; i < 4; i++) {
        for (j = 0; j < 5; j++) {
            scanf("%c", &c);
            
            if (c == '\n') break;
            b[i][j] = c;
        }
    }
    
    for (j = 0; j < 16; j++) {
        for (i = 0; i < 16; i++) {
            if (a[j/4][j%4] == '.') break;
            if (a[j/4][j%4] == b[i/4][i%4]) {
                ans += std::abs(j/4 - i/4) + std::abs(j%4 - i%4);
                break;
            }
        }
    }
    
    printf("%d", ans);
    
    return 0;
}