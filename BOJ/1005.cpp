#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>

int t, n, k, x, y, w, d, cost[1000], cnt[1000], dp[1000];
std::vector<int> graph[1000];

inline int max(int a, int b) { return a > b ? a : b; }

inline void init() {
    memset(dp, -1, sizeof(dp));
    memset(cost, 0, sizeof(cost));
    memset(cnt, 0, sizeof(cnt));

    for (int i = 0; i < n; ++i) graph[i].clear();
}

int topo() {
    int ret=0;

    std::queue<std::pair<int, int>> q;
    for (int i = 0; i < n; ++i) {
        if (cnt[i] == 0)
            q.push({ i, cost[i] });
    }

    while (!q.empty()) {
        x = q.front().first;
        y = q.front().second;
        q.pop();

        if (x == w) { ret = y; break; }

        for (const auto& g : graph[x]) {
            --cnt[g];
            dp[g] = max(dp[g], y);

            if (cnt[g] == 0) q.push({ g, dp[g]+cost[g] });
        }
    }

    return ret;
}

int main() {
    scanf("%d", &t);
    while (t--) {
        init();

        scanf("%d %d", &n, &k);
        for (int i = 0; i < n; ++i) scanf("%d", cost+i);
        while (k--) {
            scanf("%d %d", &x, &y); --x; --y;
            ++cnt[y];
            graph[x].push_back(y);
        }
        scanf("%d", &w); --w;
        printf("%d\n", topo());
    }

    return 0;
}
