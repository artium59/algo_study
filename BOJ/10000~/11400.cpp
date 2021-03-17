#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

const int MAX = 100001;
int v, e, a, b, order[MAX];
vector<int> graph[MAX];
vector<pair<int, int>> bridges;

int dfs(int cur, int parent) {
    order[cur] = ++b;
    int ret = order[cur];

    for (const auto& g : graph[cur]) {
        if (g == parent) continue;

        if (order[g] > 0) {
            ret = min(ret, order[g]);
            continue;
        }

        int r = dfs(g, cur);

        if (r > order[cur])
            bridges.push_back({ min(cur, g), max(cur, g) });

        ret = min(ret, r);
    }

    return ret;
}

int main() {
    scanf("%d %d", &v, &e);
    while (e--) {
        scanf("%d %d", &a, &b);
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    b = 0;
    for (int i = 0; i < v; ++i) {
        if (order[i] == 0)
            dfs(i, true);
    }

    sort(bridges.begin(), bridges.end());

    printf("%d\n", bridges.size());
    for (const auto& br : bridges)
        printf("%d %d\n", br.first, br.second);

    return 0;
}
