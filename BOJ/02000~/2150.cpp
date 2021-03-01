#include <cstdio>
#include <algorithm>
#include <stack>
#include <vector>
using namespace std;

int v, e, a, b;
vector<int> graph[10001], rev_graph[10001], vec;
stack<int> stk;
vector<vector<int>> scc;
bool visited[10001];    

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
        if (!visited[rg]) continue;
        visited[rg] = false;
        dfs2(rg);
    }

    vec.push_back(cur);
}

int main() {
    scanf("%d %d", &v, &e);
    while (e--) {
        scanf("%d %d", &a, &b);
        graph[a].push_back(b);
        rev_graph[b].push_back(a);
    }

    for (int i = 1; i <= v; ++i) {
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

        sort(vec.begin(), vec.end());
        scc.push_back(vec);
        vec.clear();
    }

    sort(scc.begin(), scc.end(), [](const auto& a_vec, const auto& b_vec) {
        return a_vec[0] < b_vec[0];
    });

    printf("%d\n", scc.size());
    for (const auto& sc : scc) {
        for (const auto& s : sc)
            printf("%d ", s);
        printf("-1\n");
    }

    return 0;
}
