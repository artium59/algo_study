#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int n, m, k, v, w;
bool visited[10000];
vector<int> graph[10000];
priority_queue<pair<int, int>> friends;

int Find() {
    int cur, cost, money = 0;
    queue<int> q;

    while (!friends.empty()) {
        cost = -friends.top().first;
        cur = friends.top().second;
        friends.pop();

        if (visited[cur]) continue;

        money += cost;
        q.push(cur);
        while (!q.empty()) {
            cur = q.front();
            q.pop();

            if (visited[cur]) continue;
            visited[cur] = true;

            for (const auto& g : graph[cur]) {
                if (!visited[g]) q.push(g);
            }
        }
    }

    return money;
}

int main() {
    scanf("%d %d %d", &n, &m, &k);
    for (int i = 0; i < n; i++) {
        scanf("%d", &v);
        friends.push(make_pair(-v, i));
    }
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &v, &w);
        graph[v-1].push_back(w-1);
        graph[w-1].push_back(v-1);
    }

    v = Find();

    if (k < v) printf("Oh no");
    else printf("%d", v);

    return 0;
}
