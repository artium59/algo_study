#include <iostream>
#include <queue>
#include <vector>

const int MAX = 987654321;
std::vector<std::pair<int, int>> graph[800];

int min(int a, int b) {
    return a < b ? a : b;
}

std::vector<int> Dijkstra(int s) {
    int cost, cur, next, nextCost;
    std::priority_queue<std::pair<int, int>> pq;
    std::vector<int> ret(800, MAX);

    pq.push(std::make_pair(0, s));
    ret[s] = 0;

    while(!pq.empty()) {
        cost = -pq.top().first;
        cur = pq.top().second;
        pq.pop();

        if (ret[cur] < cost) continue;

        for (const auto& g : graph[cur]) {
            next = g.first;
            nextCost = cost + g.second;
            if (ret[next] > nextCost) {
                ret[next] = nextCost;
                pq.push(std::make_pair(-nextCost, next));
            }
        }
    }

    return ret;
}

int main() {
    int n, e, a, b, c;
    std::vector<int> one, two, three;

    scanf("%d %d", &n, &e);
    for (int i = 0; i < e; i++) {
        scanf("%d %d %d", &a, &b, &c);
        graph[a-1].push_back(std::make_pair(b-1, c));
        graph[b-1].push_back(std::make_pair(a-1, c));
    }
    scanf("%d %d", &a, &b);

    one = Dijkstra(0);
    two = Dijkstra(n-1);
    three = Dijkstra(a-1);

    c = min(one[a-1]+two[b-1], one[b-1]+two[a-1]) + three[b-1];
    if (c >= MAX || c <= 0) c = -1;
    printf("%d", c);

    return 0;
}
