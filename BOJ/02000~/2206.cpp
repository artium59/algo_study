#include <cstdio>
#include <queue>
#include <tuple>

const int xrr[4]={1,-1,0,0}, yrr[4]={0,0,1,-1};
int n, m, y = 0, x = 0;
char ch;
bool maze[1000][1000], visited[1000][1000][2], c, check;

int BFS() {
    int z, nx, ny, ret = -1;
    std::queue<std::tuple<int, int, int, bool>> q;
    
    q.push(std::make_tuple(0, 0, 1, false));
    visited[0][0][0] = visited[0][0][1] = true;
    while (!q.empty()) {
        y = std::get<0>(q.front());
        x = std::get<1>(q.front());
        z = std::get<2>(q.front());
        check = std::get<3>(q.front());
        q.pop();
        
        if (y == n-1 && x == m-1) { ret = z; break; }
        
        for (int i = 0; i < 4; i++) {
            c = check;
            ny = y + yrr[i]; nx = x + xrr[i];
            
            if (!maze[ny][nx]) {
                if (c) continue;
                c = true;
            }
            
            if (0<=ny&&ny<n && 0<=nx&&nx<m && !visited[ny][nx][c]) {
                visited[ny][nx][c] = true;
                q.push(std::make_tuple(ny, nx, z+1, c));
            }
        }
    }
    
    return ret;
}

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf(" %c", &ch);
            maze[i][j] = ch == '0';
        }
    }
    
    printf("%d", BFS());
    
    return 0;
}
