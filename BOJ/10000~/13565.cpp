#include <cstdio>
#include <queue>

const int xrr[] {1,-1,0,0}, yrr[] {0,0,1,-1};
int m, n, x, y, nx, ny;
char ch;
bool grid[1000][1000], is_find;

void BFS(int x) {
    std::queue<std::pair<int, int>> q;
    
    q.push({ 0, x });
    while (!q.empty()) {
        y = q.front().first;
        x = q.front().second;
        q.pop();
        
        if (y == m-1) { is_find = true; break; }
        
        for (int i = 0; i < 4; i++) {
            ny = y+yrr[i]; nx = x+xrr[i];
            
            if (0<=ny&&ny<m && 0<=nx&&nx<n && grid[ny][nx]) {
                grid[ny][nx] = false;
                q.push({ ny, nx });
            }
        }
    }
}

int main() {
    scanf("%d %d", &m ,&n);
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf(" %c", &ch);
            if (ch == '0') grid[i][j] = true;
        }
    }
    
    for (int j = 0; j < n && !is_find; j++) {
        if (grid[0][j]) BFS(j);
    }
    
    printf(is_find ? "YES" : "NO");
    
    return 0;
}
