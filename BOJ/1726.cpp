#include <stdio.h>
#include <cstring>
#include <queue>

struct Robot {
  int y, x, dir, cnt;
    Robot() : y(0), x(0), dir(0), cnt(0) {}
    Robot(int a, int b, int c, int d) : y(a), x(b), dir(c), cnt(d) {}
  
    bool operator < (const Robot& right) const {
        return cnt > right.cnt;
    }
};

const int xrr[4] = { 1, -1, 0, 0 }, yrr[4] = { 0, 0, 1, -1 };
int n, m;
Robot start, end;
bool map[100][100], visited[100][100];

int BFS() {
    int x, y, ny, nx, k, dir, cnt, ret;
    std::priority_queue<Robot> q;
    q.push(start);
  
    while (!q.empty()) {
        y = q.top().y;
        x = q.top().x;
        dir = q.top().dir;
        cnt = q.top().cnt;
        q.pop();
        
        if (y == end.y && x == end.x) {
            if (dir == end.dir) ret = cnt;
            else if (dir+end.dir == 3 || dir+end.dir == 7) ret = cnt+2;
            else ret = cnt+1;
            break;
        }
    
        if (!map[y][x] || visited[y][x]) continue;
        visited[y][x] = true;
    
        if (-1 < y && y < m && -1 < x && x < n) {
            for (int i = 0; i < 4; i++) {
                if (i+1 == dir) k = 0;
                else if (i+1+dir == 3 || i+1+dir == 7) k = 2;
                else k = 1;
          
                for (int j = 1; j < 4; j++) {
                    ny = y+j*yrr[i]; nx = x+j*xrr[i];
          
                   if (!map[ny][nx]) break;
                   if (ny < 0 || ny >= m || nx < 0 || nx >= n) break;
          
                   if (!visited[ny][nx]) q.push(Robot(ny, nx, i+1, cnt+k+1));
                }
            }
        }
    }
  
    return ret;
}

int main() {
    int a, b, c;
  
    memset(visited, false, sizeof(visited));
  
    scanf("%d %d", &m, &n);
  
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &a);
            map[i][j] = (a == 0);
        }
    }
    scanf("%d %d %d", &a, &b, &c);
    start.y = a-1; start.x = b-1; start.dir = c;
    scanf("%d %d %d", &a, &b, &c);
    end.y = a-1; end.x = b-1; end.dir = c;
  
    printf("%d", BFS());
  
    return 0;
}
