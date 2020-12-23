#include <iostream>
#include <queue>
#include <vector>
using namespace std;

const int MAX = 87654321;
int n, m, a, b, c;
bool checker;
vector<bool> inq;
vector<int> dist, ans;
vector<pair<int, int>> graph[1000], inv_graph[1000];

void spfa() {
    int cur;
    queue<int> q;

    inq = vector<bool>(n, false);

    q.push(a);
    dist[a] = 0;
    inq[a] = true;

    while (!q.empty()) {
        cur = q.front();
        q.pop();
        inq[cur] = false;

        for (const auto& g : graph[cur]) {
            if (dist[cur] + g.second > dist[g.first]) continue;
            dist[g.first] = dist[cur] + g.second;

            if (inq[g.first]) continue;
            inq[g.first] = true;
            q.push(g.first);
        }
    }
}

bool dfs(int cur) {
    ans.push_back(cur);

    if (cur == a)
        return true;

    for (const auto& g : inv_graph[cur]) {
        if (dist[cur] - dist[g.first] == g.second)
            return dfs(g.first);
    }

    ans.pop_back();
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    while (m--) {
        cin >> a >> b >> c;
        graph[a-1].push_back({ b-1, c });
        inv_graph[b-1].push_back({ a-1, c });
    }
    cin >> a >> b; --a; --b;

    dist = vector<int>(n, MAX);
    spfa();
    dfs(b);

    cout << dist[b] << '\n' << ans.size() << '\n';
    while (!ans.empty()) {
        cout << ans.back()+1 << ' ';
        ans.pop_back();
    }

    return 0;
}
