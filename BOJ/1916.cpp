#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

const int MAX = 987654321;
int dist[1000];
std::vector<std::pair<int, int>> cities[1000];

void Dijkstra(int start) {
    int cur, cost, next, nextCost;
    std::priority_queue<std::pair<int, int>> pq;
    pq.push(std::make_pair(0, start));

    while (!pq.empty()) {
        cost = -pq.top().first;
        cur = pq.top().second;
        pq.pop();

        if (dist[cur] < cost) continue;

        for (const auto& c : cities[cur]) {
            next = c.first;
            nextCost = cost + c.second;

            if (dist[next] > nextCost) {
                dist[next] = nextCost;
                pq.push(std::make_pair(-nextCost, next));
            }
        }
    }
}

int main() {
    int n, m, a, b, c;

    std::fill(dist, dist+1000, MAX);

    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", &a, &b, &c);
        cities[a-1].push_back(std::make_pair(b-1, c));
    }
    scanf("%d %d", &a, &b);

    Dijkstra(a-1);
    printf("%d", dist[b-1]);

    return 0;
}
