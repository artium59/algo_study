#include <cstdio>
#include <vector>

int n, m, a, b;
bool ans, visited[2000];
std::vector<int> graph[2000];

void dfs(int cur, int cnt) {
    if (cnt > 4 || ans) {
        ans = true; return;
    }

    for (const auto& g : graph[cur]) {
        if (visited[g]) continue;

        visited[g] = true;
        dfs(g, cnt+1);
        visited[g] = false;
    }
}

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &a, &b);
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    for (int i = 0; i < n && !ans; i++) {
        visited[i] = true;
        dfs(i, 1);
        visited[i] = false;
    }

    printf("%d", ans);
    return 0;
}
