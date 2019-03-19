#include <iostream>
#include <cstring>
#include <tuple>
#include <queue>

const int xrr[4] = { 1, -1, 0, 0 }, yrr[4] = { 0, 0, 1, -1 };
int h, w, n, x, y, ans = 0;
char ch;
bool map[1000][1000], visited[1000][1000];
std::priority_queue<std::tuple<int, int, int>> pq;

int BFS(int b, int a) {
    int nx, ny, ret = 0;
    std::queue<std::tuple<int, int, int>> q;
    q.push(std::make_tuple(y, x, ret));
    
    memset(visited, false, sizeof(visited));
    
    while (!q.empty()) {
        y = std::get<0>(q.front());
        x = std::get<1>(q.front());
        ret = std::get<2>(q.front());
        q.pop();
        
        if (y == b && x == a) break;
        if (visited[y][x]) continue;
        visited[y][x] = true;
        
        for (int i = 0; i < 4; i++) {
            ny = y+yrr[i], nx = x+xrr[i];
            
            if (-1<ny && ny<h && -1<nx && nx<w && map[ny][nx] && !visited[ny][nx])
                q.push(std::make_tuple(ny, nx, ret+1));
        }
    }
    
    return ret;
}

int main() {
    scanf("%d %d %d", &h, &w, &n);
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            scanf(" %c", &ch);
            map[i][j] = (ch != 'X');
            
            if (ch == 'S') { y = i; x = j; }
            else if ('1' <= ch && ch <='9') pq.push(std::make_tuple(-(ch-'0'), i, j));
        }
    }
    
    while (!pq.empty()) {
        ans += BFS(std::get<1>(pq.top()), std::get<2>(pq.top()));
        pq.pop();
    }
    
    printf("%d", ans);
    
    return 0;
}
