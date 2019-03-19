#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>

const int xrr[4] = { 1, -1, 0, 0 }, yrr[4] = { 0, 0, 1, -1 };
int iceA[300][300], iceB[300][300];
bool visited[300][300];

int BFS(int b, int a) {
    int x, y, ret = 0;
    std::queue<std::pair<int, int>> q;
    q.push(std::make_pair(b, a));
    
    memset(visited, false, sizeof(visited));
    
    while (!q.empty()) {
        y = q.front().first;
        x = q.front().second;
        q.pop();
        
        if (visited[y][x]) continue;
        visited[y][x] = true; ret++;
        
        for (int i = 0; i < 4; i++) {
            if (iceA[y-yrr[i]][x-xrr[i]] > 0 && !visited[y-yrr[i]][x-xrr[i]])
                q.push(std::make_pair(y-yrr[i], x-xrr[i]));
        }
    }
    
    return ret;
}

int main() {
    int m, n, x, y, ret = 0, cnt = 0, ans = 0;
    bool isBreak;
    
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &iceA[i][j]);
            if (iceA[i][j] > 0) ret++;
        }
    }
    
    for ( ; ; ans++) {
        isBreak = false;
        
        for (y = 1; y < n-1; y++) {
            for (x = 1; x < m-1; x++) {
                if (iceA[y][x] > 0) {
                    isBreak = true; break;
                }
            }
            if (isBreak) break;
        }
        
        if (!isBreak) { ans = 0; break; }
        if (ret > BFS(y, x)) break;
        
        for (int i = 1; i < n-1; i++) {
            for (int j = 1; j < m-1; j++) {
                if (iceA[i][j] > 0) {
                    cnt = 0;
                    for (int k = 0; k < 4; k++) {
                        if (iceA[i-yrr[k]][j-xrr[k]] == 0) cnt++;
                    }

                    iceB[i][j] = iceA[i][j] - cnt;
                    if (iceB[i][j] <= 0) {
                        iceB[i][j] = 0;
                        ret--;
                    }
                }
            }
        }
        
        /* for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                printf("%d ", iceA[i][j]);
            }
            printf("\n");
        }
        printf("\n"); */
        
        if (ret == 0) { ans = 0; break; }
        std::copy(&iceB[0][0], &iceB[0][0] + 300*300, &iceA[0][0]);
    }
    
    printf("%d", ans);
    
    return 0;
}
