#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int n, m, a, b, cur, cnt[32001];
bool visited[32001];
vector<int> graph[32001];

void topo() {
    priority_queue<int> pq;

    for (int i = 1; i <= n; ++i) {
        if (cnt[i] == 0) {
            pq.push(-i);
            visited[i] = true;
        }
    }

    while (!pq.empty()) {
        cur = -pq.top();
        pq.pop();

        printf("%d ", cur);

        for (const auto& g : graph[cur]) {
            if (visited[g]) continue;

            if (--cnt[g] == 0) {
                pq.push(-g);
                visited[g] = true;
            }
        }
    }
}

int main() {
    scanf("%d %d", &n, &m);
    while (m--) {
        scanf("%d %d", &a, &b);
        graph[a].push_back(b);
        ++cnt[b];
    }
    topo();

    return 0;
}
