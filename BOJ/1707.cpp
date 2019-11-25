#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>

int k, v, e, a, b, color[20000];
bool poss;
std::vector<int> graph[20000];

inline void init() {
    poss = true;
    memset(color, 0, sizeof(color));
    for (int i = 0; i < v; ++i) graph[i].clear();
}

bool bfs(int start) {
    std::queue<int> q;

    q.push(start);
    while (!q.empty()) {
        a = q.front();
        q.pop();

        for (const auto& g : graph[a]) {
            if (color[g] == 0) {
                color[g] = -color[a];
                q.push(g);
            }
            else {
                if (color[g] == color[a]) return false;
                else continue;
            }
        }
    }

    return true;
}

int main() {
    scanf("%d", &k);
    while (k--) {
        init();

        scanf("%d %d", &v, &e);
        while (e--) {
            scanf("%d %d", &a, &b);
            graph[a-1].push_back(b-1);
            graph[b-1].push_back(a-1);
        }
        for (int i = 0; i < v; ++i) {
            if (!poss) break;
            if (color[i] != 0) continue;

            color[i] = -1;
            poss = bfs(i);
        }

        printf(poss ? "YES\n" : "NO\n");
    }

    return 0;
}
