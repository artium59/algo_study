#include <iostream>
#include <queue>

const int xrr[8] = {1, 1, 1, 0, 0, -1, -1, -1}, yrr[8] = {1, 0, -1, 1, -1, 1, 0, -1};
int w, h, ans;
bool map[50][50];

void BFS(int b, int a) {
    int x, y, ny, nx;
    std::queue<std::pair<int, int>> q;
    q.push(std::make_pair(b, a));
    
    while (!q.empty()) {
        y = q.front().first;
        x = q.front().second;
        q.pop();
        
        if (!map[y][x]) continue;
        map[y][x] = false;
        
        for (int i = 0; i < 8; i++) {
            ny = y+yrr[i], nx = x+xrr[i];
            
            if (-1<ny && ny<h && -1<nx && nx<w && map[ny][nx])
                q.push(std::make_pair(ny, nx));
        }
    }
}

int main() {
    while (true) {
        scanf("%d %d", &w, &h);
        
        if (w == 0 && h == 0) break;
        
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                scanf("%d", &ans);
                map[i][j] = (ans == 1);
            }
        }
        
        ans = 0;
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                if (map[i][j]) {
                    BFS(i, j); ans++;
                }
            }
        }
        
        printf("%d\n", ans);
    }
    
    return 0;
}
