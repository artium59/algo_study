#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>

bool map[102][102], visited[102][102];
int xrr[4] = { 1, -1, 0, 0 }, yrr[4] = { 0, 0, 1, -1, };

int DFS(int y, int x) {
    int ret = 1;
    visited[y][x] = true;
    
    for (int i = 0; i < 4; i++) {
        if (!visited[y-yrr[i]][x-xrr[i]] && map[y-yrr[i]][x-xrr[i]])
            ret += DFS(y-yrr[i], x-xrr[i]);
    }
    
    return ret;
}

int main() {
    int m, n, k, a, b, c, d;
    std::vector<int> ans;
    
    memset(map, true, sizeof(map));
    memset(visited, false, sizeof(visited));
    
    scanf("%d %d %d", &m, &n, &k);
    for (int h = 0; h < k; h++) {
        scanf("%d %d %d %d", &a, &b, &c, &d);
        for (int i = a+1; i < c+1; i++) {
            for (int j = b+1; j < d+1; j++)
                map[j][i] = false;
        }
    }
    
    for (int i = 0; i < 102; i++) {
        map[0][i] = false; map[i][0] = false;
        map[m+1][i] = false; map[i][n+1] = false;
    }
    
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j<= n; j++) {
            if (!visited[i][j] && map[i][j]) ans.push_back(DFS(i, j));
        }
    }
    
    sort(ans.begin(), ans.end());
    
    printf("%d\n", ans.size());
    for (const auto& a : ans)
        printf("%d ", a);
    
    return 0;
}
