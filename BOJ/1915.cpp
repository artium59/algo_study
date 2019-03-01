#include <iostream>

int map[1000][1000];

int max(int a, int b) {
    return a > b ? a : b;
}

int min(int a, int b, int c) {
    if (a < b) return a < c ? a : c;
    else return b < c ? b : c;
}

int main() {
    int n, m, ans = 0;
    char c;
    
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf(" %c", &c);
            map[i][j] = c == '0' ? 0 : 1;
        }
    }
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (i == 0 || j == 0) ans = max(ans, map[i][j]);
            else {
                if (map[i-1][j-1] > 0 && map[i][j-1] > 0 && map[i-1][j] > 0 && map[i][j] > 0) {
                    map[i][j] += min(map[i-1][j-1], map[i][j-1], map[i-1][j]);
                    ans = max(ans, map[i][j]);
                }
            }
        }
    }
    
    printf("%d", ans * ans);
    
    return 0;
}
