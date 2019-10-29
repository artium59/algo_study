#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <vector>

int n, m, v, a, b;
bool visited[1001];
std::vector<int> graph[1001];

void DFS(int cur) {
    visited[cur] = true;
    printf("%d ", cur);

    for (const auto& g : graph[cur]) {
        if (visited[g]) continue;
        DFS(g);
    }
}

void BFS() {
    std::queue<int> q;
    q.push(v);

    while (!q.empty()) {
        m = q.front();
        q.pop();

        printf("%d ", m);
        for (const auto& g : graph[m]) {
            if (visited[g]) continue;

            visited[g] = true;
            q.push(g);
        }
    }
}

int main() {
    scanf("%d %d %d", &n, &m, &v);
    while (m--) {
        scanf("%d %d", &a, &b);
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    for (int i = 1; i <= n; i++) sort(graph[i].begin(), graph[i].end());

    DFS(v);
    memset(visited, false, sizeof(visited));
    printf("\n"); visited[v] = true;
    BFS();

    return 0;
}
