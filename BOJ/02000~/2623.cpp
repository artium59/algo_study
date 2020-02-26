#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int n, m, t, k, line[1001];
queue<int> q;
vector<int> vec, graph[1001];

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; ++i) {
        scanf("%d", &k);
        for (int i = 0; i < k; ++i) {
            scanf("%d", &t);
            vec.push_back(t);
        }

        for (int i = 1; i < k; ++i) {
            graph[vec[i-1]].push_back(vec[i]);
            ++line[vec[i]];
        }

        vec.clear();
    }

    for (int i = 1; i <= n; ++i) {
        if (line[i] == 0) q.push(i);
    }

    while (!q.empty()) {
        k = q.front();
        vec.push_back(k);
        q.pop();

        for (const auto& g : graph[k]) {
            if (line[g] == 0) continue;
            if (--line[g] == 0) q.push(g);
        }
    }

    if (vec.size() != n)
        printf("0");
    else {
        for (const auto& v : vec)
            printf("%d\n", v);
    }

    return 0;
}
