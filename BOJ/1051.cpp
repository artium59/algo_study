#include <iostream>

char map[50][50];

int max(int a, int b) {
    return a > b ? a : b;
}

int main() {
    int n, m, ans = 1;

    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            scanf(" %c", &map[i][j]);
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            for (int k = 1; i+k < n && j+k < m; k++) {
                if (map[i][j] == map[i+k][j] && map[i][j] == map[i][j+k]) {
                    if (map[i][j] == map[i+k][j+k]) ans = max(ans, (k+1)*(k+1));
                }
            }
        }
    }

    printf("%d", ans);

    return 0;
}
