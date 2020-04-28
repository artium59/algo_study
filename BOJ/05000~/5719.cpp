#include <iostream>
#include <cstring>
#include <functional>
#include <queue>
using namespace std;

int n, m, s, d, u, v, p;
int graph[500][500], visited[500];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    function<void()> dijkstra = []() {
        int cost, cur;
        priority_queue<pair<int, int>> pq;

        pq.push({ 0, s });
        while (!pq.empty()) {
            cost = -pq.top().first;
            cur = pq.top().second;
            pq.pop();

            if (cur == d) break;

            for (int i = 0; i < n; ++i) {
                if (i == s || graph[cur][i] == 0) continue;
                if (visited[i] != -1 && cost+graph[cur][i] > visited[i]) continue;

                visited[i] = cost + graph[cur][i];
                pq.push({ -visited[i], i });
            }
        }
    };

    function<void()> bfs = []() {
        int cur;
        queue<int> q;

        q.push(d);
        while (!q.empty()) {
            cur = q.front();
            q.pop();

            if (cur == s) continue;

            for (int i = 0; i < n; ++i) {
                if (graph[i][cur] == 0 || visited[i] == -1) continue;
                if (visited[cur] - visited[i] == graph[i][cur]) {
                    graph[i][cur] = 0;
                    q.push(i);
                }
            }
        }
    };

    while (true) {
        cin >> n >> m;
        if (n + m == 0) break;

        memset(visited, -1, sizeof(visited));
        memset(graph, 0, sizeof(graph));

        cin >> s >> d;
        while (m--) {
            cin >> u >> v >> p;
            graph[u][v] = p;
        }

        visited[s] = 0;
        dijkstra();
        bfs();

        memset(visited, -1, sizeof(visited));
        visited[s] = 0;
        dijkstra();

        if (visited[d] == 0) visited[d] = -1;
        cout << visited[d] << '\n';
    }

    return 0;
}
