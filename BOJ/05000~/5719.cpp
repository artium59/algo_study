#include <iostream>
#include <cstring>
#include <functional>
#include <queue>
#include <vector>
using namespace std;

const int MAX = 7654321;
int n, m, s, d, u, v, p;
int graph[500][500];
vector<int> dist;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    function<void()> spfa = []() {
        int cur;
        queue<int> q;
        vector<bool> inq(n, false);
        dist = vector<int>(n, MAX);

        q.push(s);
        inq[s] = true;
        dist[s] = 0;

        while (!q.empty()) {
            cur = q.front();
            q.pop();
            inq[cur] = false;

            for (int i = 0; i < n; ++i) {
                if (graph[cur][i] == 0 || dist[cur] + graph[cur][i] > dist[i]) continue;

                dist[i] = dist[cur] + graph[cur][i];

                if (inq[i]) continue;
                inq[i] = true;
                q.push(i);
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
                if (graph[i][cur] == 0 || dist[i] + graph[i][cur] != dist[cur]) continue;
                graph[i][cur] = 0;
                q.push(i);
            }
        }
    };

    while (true) {
        cin >> n >> m;
        if (n + m == 0) break;

        memset(graph, 0, sizeof(graph));

        cin >> s >> d;
        while (m--) {
            cin >> u >> v >> p;
            graph[u][v] = p;
        }

        spfa();
        bfs();

        spfa();
        if (dist[d] == MAX) dist[d] = -1;
        cout << dist[d] << '\n';
    }

    return 0;
}
