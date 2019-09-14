#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>

int n, a, b, ans=-2;
bool visited[100];
std::vector<int> graph[100];

int BFS(int start) {
    int ret=1, cur;
    std::queue<int> q;
    
    q.push(start);
    while (!q.empty()) {
        cur = q.front();
        q.pop();
        
        for (const auto& g : graph[cur]) {
            if (!visited[g]) {
                visited[g] = true; ret++;
                q.push(g);
            }
        }
    }
    
    return ret;
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i < n; i++) {
        scanf("%d %d", &a, &b);
        graph[b-1].push_back(a-1);
    }
    
    for (int i = 0; i < n; i++) {
        memset(visited, false, sizeof(visited));
        if (BFS(i) == n) {
            ans = i; break;
        }
    }

    printf("%d", ans+1);

    return 0;
}
