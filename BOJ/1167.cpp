#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int v, a, b, c;
vector<bool> visited;
vector<pair<int, int>> graph[100000];

pair<int, int> bfs(int cur) {
    int cost, max_cur, max_cost;
    queue<pair<int, int>> q;

    q.push({ cur, 0 });

    visited = vector<bool>(100000);
    visited[cur] = true;

    while (!q.empty()) {
        cur = q.front().first;
        cost = q.front().second;
        q.pop();

        if (cost > max_cost) {
            max_cur = cur;
            max_cost = cost;
        }

        for (const auto& g : graph[cur]) {
            if (visited[g.first]) continue;

            visited[g.first] = true;
            q.push({ g.first, cost+g.second });
        }
    }

    return { max_cur, max_cost };
}

int main() {
    scanf("%d", &v);
    while (v--) {
        scanf("%d", &a);
        while (true) {
            scanf("%d", &b);
            if (b == -1) break;
            scanf("%d", &c);
            graph[a-1].push_back({ b-1, c });
        }
    }

    v = bfs(0).first;
    printf("%d", bfs(v).second);
    return 0;
}
