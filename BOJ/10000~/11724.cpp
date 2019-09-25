#include <cstdio>
#include <queue>
#include <vector>

int n, m, a, b;
bool visited[1000];
std::vector<int> graph[1000];

void BFS(int z) {
    std::queue<int> q;
    
    q.push(z);
    visited[z] = true;
    while (!q.empty()) {
        a = q.front();
        q.pop();
        
        for (const auto& g : graph[a]) {
            if (!visited[g]) visited[g] = true, q.push(g);
        }
    }
}

int main() {
    scanf("%d %d", &n, &m);
    while (m--) {
        scanf("%d %d", &a, &b);
        graph[a-1].push_back(b-1);
        graph[b-1].push_back(a-1);
    }
    
    for (int i = 0; i < n; i++) {
        if (!visited[i]) m++, BFS(i);
    }

    printf("%d", m+1);

    return 0;
}
