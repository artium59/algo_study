#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>

int n, t, u, ans=1e9, people[10];
bool visited[10], area[10];
std::vector<int> graph[10];

void DFS(int start, bool is_first) {
    visited[start] = true;
    for (const auto& g : graph[start]) {
        if (!visited[g] && is_first == area[g])
            DFS(g, is_first);
    }
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) scanf("%d", people+i);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &t);
        while (t--) {
            scanf("%d", &u);
            graph[i].push_back(u-1);
        }
    }

    for (int k = 0; k < n/2+n%2; ++k) {
        area[k] = true;

        do {
            t = 0;
            memset(visited, false, sizeof(visited));

            for (int i = 0; i < n; ++i) {
                if (area[i]) { DFS(i, true); break; }
            }
            for (int i = 0; i < n; ++i) {
                if (!area[i]) { DFS(i, false); break; }
            }

            for (int i = 0; i < n; ++i) {
                if (!visited[i]) { t=1e9; break; }
            }

            if (t == 1e9) continue;

            t = u = 0;
            for (int i = 0; i < n; i++) {
                if (area[i]) t += people[i];
                else u += people[i];
            }

            ans = ans < abs(t-u) ? ans : abs(t-u);
        } while (std::prev_permutation(area, area+n));
    }

    if (ans == 1e9) ans = -1;
    printf("%d", ans);

    return 0;
}
