#include <iostream>
#include <cstring>
#include <queue>
#include <vector>
using namespace std;

int n, m, k, l, dir_cnt, parent[50000], cnt[50000];
char op;
bool visited[50000];
vector<int> graph[50000];
vector<pair<int, int>> vec;

bool topo() {
    int cur;
    queue<int> q;

    for (int i = 0; i < n; ++i) {
        if (cnt[parent[i]] == 0 && !visited[parent[i]]) {
            q.push(parent[i]);
            visited[parent[i]] = true;
        }
    }

    while (!q.empty()) {
        cur = q.front();
        q.pop();

        for (const auto& g : graph[cur]) {
            if (visited[g]) continue;

            --dir_cnt;
            if (--cnt[g] == 0) {
                q.push(g);
                visited[g] = true;
            }
        }
    }

    return dir_cnt == 0;
}

int find(int x) {
    if (parent[x] == x) return x;
    else return parent[x] = find(parent[x]);
}

void Union(int x, int y) {
    int fx = find(x), fy = find(y);
    if (fx == fy) return;

    if (cnt[fx] < cnt[fy])
        parent[fx] = fy;
    else if (cnt[fx] > cnt[fy])
        parent[fy] = fx;
    else {
        parent[fx] = fy;
        ++cnt[fy];
    }
}

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; ++i)
        parent[i] = i;

    while (m--) {
        scanf("%d %c %d", &k, &op, &l);
        if (op == '=')
            Union(k, l);
        else
            vec.push_back({ k, l });
    }

    memset(cnt, 0, sizeof(cnt));
    for (const auto& v : vec) {
        k = find(v.first); l = find(v.second);
        graph[k].push_back(l);
        ++cnt[l];
        ++dir_cnt;
    }

    if (!topo()) printf("in");
    printf("consistent");

    return 0;
}
