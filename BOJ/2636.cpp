#include <stdio.h>
#include <cstring>
#include <queue>

int n, m, xrr[4] = { 1, -1, 0, 0 }, yrr[4] = { 0, 0, 1, -1 };
short cheese[102][102];
bool isAir[102][102];

void BFS(int b, int a) {
    int y, x;
    std::queue<std::pair<int, int>> q;
    q.push(std::make_pair(b, a));
  
    while (!q.empty()) {
        y = q.front().first;
        x = q.front().second;
        q.pop();
    
        if (isAir[y][x]) continue;
        isAir[y][x] = true;
    
        for (int i = 0; i < 4; i++) {
            if (cheese[y-yrr[i]][x-xrr[i]] == 0)
                q.push(std::make_pair(y-yrr[i], x-xrr[i]));
        }
    }
}

std::vector<std::pair<int, int>> Melt() {
    bool swch = false;
    std::vector<std::pair<int, int>> ret;
  
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            swch = false;
                for (int k = 0; k < 4; k++) {
                    if (cheese[i][j] == 1 && isAir[i-yrr[k]][j-xrr[k]]) {
                        swch = true; break;
                    }
                }
      
            if (swch) {
                ret.push_back(std::make_pair(i, j));
                cheese[i][j] = 0;
            }
        }
    }
  
    return ret;
}

int main() {
    int t, ans = 0, cnt = 0;
    std::vector<std::pair<int, int>> vp;
  
    memset(isAir, false, sizeof(isAir));
    memset(cheese, -1, sizeof(cheese));
  
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            scanf("%hd", &cheese[i][j]);
            if (cheese[i][j] == 0) ans++;
        }
    }
    
    BFS(1, 1);
    t = n*m - ans;
    while (t > 0) {
        ans = t;
        vp = Melt();
        cnt++;
    
        for (const auto& v : vp) {
            if (!isAir[v.first][v.second])
                BFS(v.first, v.second);
        }
        t -= vp.size();
    }
  
    printf("%d\n%d", cnt, ans);
  
    return 0;
}