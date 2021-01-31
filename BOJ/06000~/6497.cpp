#include <iostream>
#include <queue>
#include <tuple>
using namespace std;

const int MAX = 200000;
int n, m, x, y, z, ans, parent[MAX], ranking[MAX];
priority_queue<tuple<int, int, int>> pq;

int find(int a) {
    if (a == parent[a]) return a;
    else return parent[a] = find(parent[a]);
}

void Union(int a, int b) {
    int pa = find(a), pb = find(b);
    if (pa == pb) return;

    if (ranking[pa] < ranking[pb])
        parent[pa] = pb;
    else if (ranking[pa] > ranking[pb])
        parent[pb] = pa;
    else {
        ++ranking[pa];
        parent[pb] = pa;
    }
}

int main() {
    while (true) {
        scanf("%d %d", &m, &n);
        if (m+n == 0) break;

        for (int i = 0; i < m; ++i) {
            parent[i] = i;
            ranking[i] = 0;
        }

        ans = 0;
        while (n--) {
            scanf("%d %d %d", &x, &y, &z);
            ans += z;
            pq.push({ -z, x, y });
        }

        while (!pq.empty()) {
            z = -get<0>(pq.top());
            x = get<1>(pq.top());
            y = get<2>(pq.top());
            pq.pop();

            x = find(x);
            y = find(y);
            if (x == y) continue;

            Union(x, y);
            ans -= z;
        }

        printf("%d\n", ans);
    }

    return 0;
}
