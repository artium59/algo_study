#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int n, a, b, c;
vector<bool> visited;
vector<pair<int, int>> graph[10000];

pair<int, int> bfs(int start) {
    pair<int, int> cur, ret = { 0, 0 };
    queue<pair<int, int>> q;

    visited = vector<bool>(n, false);

    q.push({ start, 0 });
    visited[start] = true;

    while (!q.empty()) {
        cur = q.front();
        q.pop();

        if (ret.second < cur.second)
            ret = cur;

        for (const auto& g : graph[cur.first]) {
            if (visited[g.first]) continue;

            visited[g.first] = true;
            q.push({ g.first , cur.second + g.second });
        }
    }

    return ret;
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n-1; ++i) {
        scanf("%d %d %d", &a, &b, &c);
        graph[a-1].push_back({ b-1, c });
        graph[b-1].push_back({ a-1, c });
    }

    auto p = bfs(0);
    p = bfs(p.first);

    printf("%d", p.second);
    return 0;
}
