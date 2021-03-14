#include <iostream>
#include <queue>
#include <vector>
using namespace std;

const int MAX = 10000;
int v, e, a, b, order[MAX];
bool articulation[MAX];
vector<int> graph[MAX];

int dfs(int cur, bool root) {
    order[cur] = ++b;
    int ret = order[cur], child = 0;

    for (const auto& g : graph[cur]) {
        if (order[g] > 0) {
            ret = min(ret, order[g]);
            continue;
        }

        ++child;
        int r = dfs(g, false);

        if (!root && r >= order[cur])
            articulation[cur] = true;

        ret = min(ret, r);
    }

    if (root)
        articulation[cur] = child > 1;

    return ret;
}

int main() {
    scanf("%d %d", &v, &e);
    while (e--) {
        scanf("%d %d", &a, &b); --a; --b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    b = 0;
    for (int i = 0; i < v; ++i) {
        if (order[i] == 0)
            dfs(i, true);
    }

    b = 0;
    for (int i = 0; i < v; ++i) {
        if (articulation[i])
            ++b;
    }

    printf("%d\n", b);
    for (int i = 0; i < v; ++i) {
        if (articulation[i])
            printf("%d ", i+1);
    }

    return 0;
}
