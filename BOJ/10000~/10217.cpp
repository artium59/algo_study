#include <cstdio>
#include <cstring>
#include <queue>
#include <tuple>
#include <vector>
using namespace std;

int tc, n, m, k, u, v, c, d, visited[100][10001];
vector<tuple<int, int, int>> graph[100];

int dijkstra() {
    int ret = -1;
    priority_queue<tuple<int, int, int>> pq;

    pq.push({ 0, 0, 0 });
    while (!pq.empty()) {
        d = -get<0>(pq.top());
        c = -get<1>(pq.top());
        v = get<2>(pq.top());
        pq.pop();

        if (v == n) { ret = d; break; }

        for (const auto& g : graph[v]) {
            if (m < c+get<1>(g)) continue;
            if (visited[get<2>(g)][c+get<1>(g)] != -1 &&
                visited[get<2>(g)][c+get<1>(g)] <= d+get<0>(g)) continue;

            visited[get<2>(g)][c+get<1>(g)] = d + get<0>(g);
            pq.push({ -(d+get<0>(g)), -(c+get<1>(g)), get<2>(g) });
        }
    }

    return ret;
}

int main() {
    scanf("%d", &tc);
    while (tc--) {
        memset(visited, -1, sizeof(visited));

        scanf("%d %d %d", &n, &m, &k); --n;
        while (k--) {
            scanf("%d %d %d %d", &u, &v, &c, &d);
            graph[u-1].push_back({ d, c, v-1 });
        }

        k = dijkstra();
        if (k == -1) printf("Poor KCM\n");
        else printf("%d\n", k);

        for (int i = 0; i < n; i++) graph[i].clear();
    }

    return 0;
}
