#include <cstdio>
#include <stack>
#include <vector>
using namespace std;

const int MAX = 100000;
int tc, n, m, x, y, ans;
bool visited[MAX];
stack<int> stk;
vector<int> graph[MAX];

void dfs1(int cur) {
    for (const auto& g : graph[cur]) {
        if (visited[g]) continue;
        visited[g] = true;
        dfs1(g);
    }

    stk.push(cur);
}

void dfs2(int cur) {
    for (const auto& g : graph[cur]) {
        if (!visited[g]) continue;
        visited[g] = false;
        dfs2(g);
    }
}

int main() {
    scanf("%d", &tc);
    while (tc--) {
        for (int i = 0; i < n; ++i)
            graph[i].clear();

        scanf("%d %d", &n, &m);
        while (m--) {
            scanf("%d %d", &x, &y); --x; --y;
            graph[x].push_back(y);
        }

        for (int i = 0; i < n; ++i) {
            if (visited[i]) continue;
            visited[i] = true;
            dfs1(i);
        }

        y = 0;
        while (!stk.empty()) {
            x = stk.top();
            stk.pop();

            if (!visited[x]) continue;
            visited[x] = false;
            dfs2(x);
            ++y;
        }

        printf("%d\n", y);
    }

    return 0;
}
