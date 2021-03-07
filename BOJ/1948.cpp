#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int n, m, a, b, c;
vector<int> dist(10000);
vector<pair<int, int>> graph[10000], rev_graph[10000];

int spfa() {
    int cur;
    queue<int> q;
    vector<bool> inq(n, false);

    q.push(a);
    while (!q.empty()) {
        cur = q.front();
        inq[cur] = false;
        q.pop();

        if (cur == b) continue;

        for (const auto& g : graph[cur]) {
            if (dist[g.first] > dist[cur]+g.second) continue;
            dist[g.first] = dist[cur] + g.second;

            if (inq[g.first]) continue;
            inq[g.first] = true;
            q.push(g.first);
        }
    }

    return dist[b];
}

int rev_spfa() {
    int cur, ret = 0;
    queue<int> q;
    vector<bool> inq(n, false), visited(n, false);

    q.push(b);
    while (!q.empty()) {
        cur = q.front();
        inq[cur] = false;
        q.pop();

        if (cur == a) break;

        for (const auto& rg : rev_graph[cur]) {
            if (dist[cur]-dist[rg.first] != rg.second) continue;
            ++ret;

            if (visited[rg.first]) continue;
            visited[rg.first] = true;

            if (inq[rg.first]) continue;
            inq[rg.first] = true;
            q.push(rg.first);
        }
    }

    return ret;
}

int main() {
    scanf("%d %d", &n, &m);
    while (m--) {
        scanf("%d %d %d", &a, &b, &c); --a; --b;
        graph[a].push_back({ b, c });
        rev_graph[b].push_back({ a, c });
    }
    scanf("%d %d", &a, &b); --a; --b;

    printf("%d\n", spfa());
    printf("%d", rev_spfa());

    return 0;
}
