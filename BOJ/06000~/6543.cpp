#include <cstdio>
#include <algorithm>
#include <stack>
#include <vector>
using namespace std;

const int MAX = 5001;
int n, m, a, b;
vector<int> graph[MAX], rev_graph[MAX], vec, cnt, ans;
stack<int> stk;
bool flag, visited[MAX];

void dfs1(int cur) {
    for (const auto& g : graph[cur]) {
        if (visited[g]) continue;
        visited[g] = true;
        dfs1(g);
    }
    stk.push(cur);
}

void dfs2(int cur) {
    for (const auto& rg : rev_graph[cur]) {
        ++cnt[rg];
        if (!visited[rg]) continue;
        visited[rg] = false;
        dfs2(rg);
    }

    vec.push_back(cur);
}

int main() {
    while (true) {
        scanf("%d", &n);
        if (n == 0) break;
        scanf("%d", &m);

        for (int i = 1; i < 5001; ++i) {
            graph[i].clear();
            rev_graph[i].clear();            
        }
        ans.clear();
        cnt = vector<int>(n+1);

        while (m--) {
            scanf("%d %d", &a, &b);
            graph[a].push_back(b);
            rev_graph[b].push_back(a);
        }

        for (int i = 1; i <= n; ++i) {
            if (visited[i]) continue;
            visited[i] = true;
            dfs1(i);
        }

        while (!stk.empty()) {
            a = stk.top();
            stk.pop();

            if (!visited[a]) continue;
            visited[a] = false;
            dfs2(a);

            flag = true;
            for (const auto& v : vec) {
                if (cnt[v] == graph[v].size()) continue;
                flag = false;
                break;
            }

            if (flag) {
                for (const auto& v : vec)
                    ans.push_back(v);
            }

            vec.clear();
        }

        sort(ans.begin(), ans.end());
        for (int i = 0; i < ans.size(); ++i)
            printf("%d%c", ans[i], "\n "[i+1 < ans.size()]);
    }

    return 0;
}
