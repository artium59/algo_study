#include <iostream>
#include <cstring>
#include <tuple>
#include <queue>

const int xrr[4] = { 0, -1, 1, 0 }, yrr[4] = { -1, 0, 0, 1 };
int x, y, n, ans = 0, cnt = 0, size = 2, foodCnt = 0, aqua[20][20], fish[7];
bool visited[20][20];

int BFS() {
    int ny, nx, qy, qx, dist;
    bool eat = false;
    std::priority_queue<std::tuple<int, int, int>> q;
    q.push(std::make_tuple(0, -y, -x));
    
    memset(visited, false, sizeof(visited));
    
    while (!q.empty()) {
        dist = -std::get<0>(q.top());
        qy = -std::get<1>(q.top());
        qx = -std::get<2>(q.top());
        q.pop();
        
        if (0 < aqua[qy][qx] && aqua[qy][qx] < size) {
            y = qy; x = qx; aqua[qy][qx] = 0;
            fish[aqua[qy][qx]]--; cnt++;
            eat = true;
            break;
        }
        
        if (visited[qy][qx]) continue;
        visited[qy][qx] = true;
        
        for (int i = 0; i < 4; i++) {
            ny = qy + yrr[i]; nx = qx + xrr[i];
            
            if (-1<ny && ny<n && -1<nx && nx<n && !visited[ny][nx] && aqua[ny][nx] <= size)
                q.push(std::make_tuple(-dist-1, -ny, -nx));
        }
    }
    
    if (!eat) dist = 987654321;
    return dist;
}

int main() {
    memset(fish, 0, sizeof(fish));
    
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &aqua[i][j]);
            if (0 < aqua[i][j] && aqua[i][j] < 9) fish[aqua[i][j]]++;
            if (aqua[i][j] == 9) { aqua[i][j] = 0; y = i; x = j; }
        }
    }
    
    foodCnt += fish[1];
    while (foodCnt > 0) {
        ans += BFS(); foodCnt--;
        if (cnt == size) { cnt = 0; size++; foodCnt += fish[size-1]; }
        if (ans > 987654320) break;
    }
    
    if (ans > 987654320) ans -= 987654321;
    printf("%d", ans);
    
    return 0;
}
