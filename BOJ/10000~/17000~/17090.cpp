#include <cstdio>

const char direction[] {'U','R','D','L'};
const int xrr[] {0,1,0,-1}, yrr[] {-1,0,1,0};
int n, m, ans=0, visited[500][500];;
char maze[500][500];

bool DFS(int b, int a) {
    if (b<0 || b>=n || a<0 || a>=m) return true;
    
    if (visited[b][a] == 1) return true;
    if (visited[b][a] == -1) return false;
    visited[b][a] = -1;
    
    for (int i = 0; i < 4; i++) {
        if (direction[i] != maze[b][a]) continue;
        
        if (DFS(b+yrr[i], a+xrr[i])) {
            visited[b][a] = 1;
            return true;
        }
        else
            return false;
    }
}

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) 
            scanf(" %c", &maze[i][j]);
    }
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!visited[i][j]) DFS(i, j);
        }
    }
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            if (visited[i][j] == 1) ans++;
    }
    
    printf("%d", ans);

    return 0;
}
