#include <iostream>
#include <cstring>

int map[1025][1025];

int main() {
    int n, m, x1, y1, x2, y2, sum = 0;

    memset(map, 0, sizeof(map));
    
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) {
        sum = 0;
        for (int j = 1; j <= n; j++) {
            scanf("%d", &x1);
            sum += x1;
            if (i > 0) {
                sum += map[i-1][j];
                if (j > 0) sum -= map[i-1][j-1];
            }
            map[i][j] = sum;
        }
    }
    
    for (int i = 0; i < m; i++) {
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
        x1--; y1--;
        printf("%d\n", map[x2][y2] - map[x2][y1] - map[x1][y2] + map[x1][y1]);
    }
    
    return 0;
}
