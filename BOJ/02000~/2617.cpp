#include <iostream>
#include <cstring>
#include <queue>
#include <vector>

bool visited[100];

int BFS(std::vector<int> graph[], int s) {
    int start, ret = -1;
    std::queue<int> q;
    q.push(s);
    
    memset(visited, false, sizeof(visited));
    
    while (!q.empty()) {
        start = q.front();
        q.pop();
        
        if (visited[start]) continue;
        visited[start] = true; ret++;
        
        for (const auto& g : graph[start]) {
            if (!visited[g]) q.push(g);
        }
    }
    
    return ret;
}

int main() {
    int n, m, a, b, ans = 0;
    std::vector<int> heavy[100], light[100];
    
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &a, &b); // a > b
        heavy[a].push_back(b); // a가 b보다 더 무겁다
        light[b].push_back(a);
    }
    
    for (int i = 1; i <= n; i++) {
        if (n/2+1 <= BFS(light, i) || n/2+1 <= BFS(heavy, i)) ans++;
    }
    
    printf("%d", ans);
    
    return 0;
}
