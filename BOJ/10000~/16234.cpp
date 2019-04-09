#include <iostream>
#include <queue>
#include <vector>
using namespace std;

const int xrr[4] = { 1, -1, 0, 0 }, yrr[4] = { 0, 0, 1, -1 };
int n, l, r, sum, before = 0, after = 0, ans = 0, map[50][50];
bool visited[50][50];

inline int abs(int a) { return a < 0 ? -a : a; }

void Init() {
    for (int i = 0; i < 50; i++)
        fill(visited[i], visited[i]+50, false);
}

vector<pair<int, int>> BFS(int b, int a) {
    int x, y, nx, ny, t;
    queue<pair<int, int>> q;
    vector<pair<int, int>> ret;
    
    q.push(make_pair(b, a));
    while (!q.empty()) {
        y = q.front().first;
        x = q.front().second;
        q.pop();
        
        if (visited[y][x]) continue;
        visited[y][x] = true;
        ret.push_back(make_pair(y, x));
        
        for (int i = 0; i < 4; i++) {
            ny = y + yrr[i]; nx = x + xrr[i];
            t = abs(map[y][x] - map[ny][nx]);
            
            if (-1<ny&&ny<n && -1<nx&&nx<n && l<=t&&t<=r && !visited[ny][nx])
                q.push(make_pair(ny, nx));
        }
    }
    
    return ret;
}

int main() {
    scanf("%d %d %d", &n, &l, &r);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            scanf("%d", &map[i][j]);
    }
    
    while (true) {
        Init();
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                vector<pair<int, int>> vec;
                
                if (!visited[i][j]) {
                    vec = BFS(i, j); sum = 0;
                    
                    if (vec.size() > 1) {
                        for (const auto& v : vec)
                            sum += map[v.first][v.second];

                        for (const auto& v : vec)
                            map[v.first][v.second] = sum / vec.size();
                        
                        after++;
                    }
                }
            }
        }
        
        if (before == after) break;
        
        before = after; ans++;
    }
    
    printf("%d", ans);
    
    return 0;
}
