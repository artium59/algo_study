#include <iostream>
#include <queue>
#include <vector>

using namespace std;

const int MAX = 987654321;

int max(int a, int b) {
    return a > b ? a : b;
}

void Dijkstra(vector<pair<int, int>> pv[], vector<int>& d, int s) {
    int cur, cost, next, nextCost;
    priority_queue<pair<int, int>> pq;
    pq.push(make_pair(0, s));
    d[s] = 0;

    while (!pq.empty()) {
        cost = -pq.top().first;
        cur = pq.top().second;
        pq.pop();

        if (d[cur] < cost) continue;

        for (const auto& r : pv[cur]) {
            next = r.first;
            nextCost = cost + r.second;

            if (d[next] > nextCost) {
                d[next] = nextCost;
                pq.push(make_pair(-nextCost, next));
            }
        }
    }
}

int main() {
    int n, m, x, a, b, c, ans = 0;
    vector<int> dist(1000, MAX), invDist(1000, MAX);
    vector<pair<int, int>> roads[1000], invRoads[1000];

    scanf("%d %d %d", &n, &m, &x);
    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", &a, &b, &c);
        roads[a-1].push_back(make_pair(b-1, c));
        invRoads[b-1].push_back(make_pair(a-1, c));
    }

    Dijkstra(roads, dist, x-1);
    Dijkstra(invRoads, invDist, x-1);

    for (int i = 0; i < n; i++)
        ans = max(ans, dist[i] + invDist[i]);

    printf("%d", ans);

    return 0;
}
