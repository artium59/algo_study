#include <iostream>
#include <cstring>

int map[102][102];
int xrr[4] = { 1, -1, 0, 0 }, yrr[4] = { 0, 0, 1, -1 };
bool visited[102][102];

int max(int a, int b) {
    return a > b ? a : b;
}

void DFS(int y, int x, int rain) {
    if (visited[y][x]) return;
    
    visited[y][x] = true;
    for (int i = 0; i < 4; i++) {
        if (map[y-yrr[i]][x-xrr[i]] > rain && !visited[y-yrr[i]][x-xrr[i]])
            DFS(y-yrr[i], x-xrr[i], rain);
    }
}

int main() {
    int n, m = 0, size, ans = 0;
    
    memset(map, -1, sizeof(map));
    
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            scanf("%d", &map[i][j]);
            m = max(m, map[i][j]);
        }
    }
    
    for (int h = 0; h < m; h++) {
        size = 0;
        memset(visited, false, sizeof(visited));
        
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (!visited[i][j] && map[i][j] > h) {
                    DFS(i, j, h); size++;
                }
            }
        }
        
        ans = max(ans, size);
    }
    
    printf("%d", ans);
    
    return 0;
}
