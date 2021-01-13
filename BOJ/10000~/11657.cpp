#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int n, m, a, b, c, visited[501];
long long dist[501];
bool inq[501];
vector<pair<int, int>> graph[501];

bool find() {
    queue<int> q;

    q.push(1);
    inq[1] = true;
    while (!q.empty()) {
        a = q.front();
        q.pop();
        inq[a] = false;

        if (visited[a] > n) return false;

        for (const auto& g : graph[a]) {
            if (dist[g.first] <= dist[a] + g.second) continue;
            dist[g.first] = dist[a] + g.second;

            if (inq[g.first]) continue;
            q.push(g.first);
            ++visited[g.first];
            inq[g.first] = true;
        }
    }

    return true;
}

int main() {
    scanf("%d %d", &n, &m);
    while (m--) {
        scanf("%d %d %d", &a, &b, &c);
        graph[a].push_back({ b, c });
    }

    for (int i = 2; i <= n; ++i)
        dist[i] = 1e9;

    if (find()) {
        for (int i = 2; i <= n; ++i) {
            if (dist[i] == 1e9) dist[i] = -1;
            printf("%lld\n", dist[i]);
        }
    }
    else
        printf("-1");

    return 0;
}
