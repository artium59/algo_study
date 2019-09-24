#include <cstdio>
#include <cstring>
#include <queue>
#include <tuple>

const int xrr[4] = {1,-1,0,0}, yrr[4] = {0,0,1,-1};
int tc, ans, size, x, y, cnt, cur_y, cur_x, nx, ny;
char build[1000][1000];
bool visited[1000][1000];
std::queue<std::pair<int, int>> fire;
std::queue<std::tuple<int, int, int>> q;

int BFS() {
    int ret = -1;
    
    while (!q.empty()) {
        size = fire.size();
        for (int i = 0; i < size; i++) {
            cur_y = fire.front().first;
            cur_x = fire.front().second;
            fire.pop();
            
            for (int i = 0; i < 4; i++) {
                ny = cur_y+yrr[i]; nx = cur_x+xrr[i];
                
                if (0<=ny&&ny<y && 0<=nx&&nx<x && build[ny][nx]=='.') {
                    visited[ny][nx] = true;
                    build[ny][nx] = '*';
                    fire.push({ ny, nx });
                }
            }
        }
        
        size = q.size();
        for (int i = 0; i < size; i++) {
            cur_y = std::get<0>(q.front());
            cur_x = std::get<1>(q.front());
            cnt = std::get<2>(q.front());
            q.pop();
            
            if (cur_y == 0 || cur_x == 0) { ret = cnt; goto RET; }
            if (cur_y == y-1 || cur_x == x-1) { ret = cnt; goto RET; }
            
            for (int i = 0; i < 4; i++) {
                ny = cur_y+yrr[i]; nx = cur_x+xrr[i];
                
                if (0<=ny&&ny<y && 0<=nx&&nx<x && !visited[ny][nx] && build[ny][nx]=='.') {
                    visited[ny][nx] = true;
                    q.push(std::make_tuple(ny, nx, cnt+1));
                }
            }
        }
    }
    
    RET:
    return ret;
}

int main() {
    scanf("%d", &tc);
    while (tc--) {
        scanf("%d %d", &x, &y);
        for (int i = 0; i < y; i++) {
            for (int j = 0; j < x; j++) {
                scanf(" %c", &build[i][j]);
                if (build[i][j] == '@') q.push(std::make_tuple(i, j, 1));
                if (build[i][j] == '*') fire.push({ i, j });
            }
        }
        
        ans = BFS();
        if (ans == -1) printf("IMPOSSIBLE\n");
        else printf("%d\n", ans);
        
        while (!q.empty()) q.pop();
        while (!fire.empty()) fire.pop();
        memset(visited, false, sizeof(visited));
    }
    
    return 0;
}
