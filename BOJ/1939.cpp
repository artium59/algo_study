#include <iostream>
#include <cstring>
#include <queue>
#include <vector>
using namespace std;

const int MAX = 1e9+1;
int n, m, a, b, c, l, r=MAX, mid, cur;
bool visited[10000];
vector<pair<int, int>> graph[10000];

bool bfs() {
    std::queue<int> q;
    memset(visited, false, sizeof(visited));

    q.push(a);
    while (!q.empty()) {
        cur = q.front();
        q.pop();

        if (cur == b) return true;

        for (const auto& g : graph[cur]) {
            if (visited[g.first] || mid > g.second) continue;

            visited[g.first] = true;
            q.push(g.first);
        }
    }

    return false;
}

int main() {
    scanf("%d %d", &n, &m);
    while (m--) {
        scanf("%d %d %d", &a, &b, &c); --a; --b;
        graph[a].push_back({ b, c });
        graph[b].push_back({ a, c });
    }
    scanf("%d %d", &a, &b); --a; --b;

    while (l+1 < r) {
        mid = (l + r) / 2;

        if (bfs()) l = mid;
        else r = mid;
    }

    printf("%d", l);

    return 0;
}
