#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

const int MAX = 987654321;
int cache[20000];
std::vector<std::pair<int, int>> graph[20000];

int min(int a, int b) {
    return a < b ? a : b;
}

void BFS(int s) {
    int cur, cost, next, nextCost;
    std::priority_queue<std::pair<int, int>> pq;
    pq.push(std::make_pair(0, s));
    
    while (!pq.empty()) {
        cost = -pq.top().first;
        cur = pq.top().second;
        pq.pop();

        if (cache[cur] < cost) continue;

        for (const auto& g : graph[cur]) {
            next = g.first;
            nextCost = cost + g.second;

            if (cache[next] > nextCost) {
                cache[next] = nextCost;
                pq.push(std::make_pair(-nextCost, next));
            }
        }
    }
}

int main() {
    int v, e, k, a, b, c, minCost, minIndex;
    
    std::fill(cache, cache+20000, MAX);
    
    scanf("%d %d %d", &v, &e, &k);
    for (int i = 0; i < e; i++) {
        scanf("%d %d %d", &a, &b, &c);
        graph[a-1].push_back(std::make_pair(b-1, c));
    }
    
    cache[k-1] = 0;
    BFS(k-1);
    for (int i = 0; i < v; i++) {
        if (cache[i] == MAX) printf("INF\n");
        else printf("%d\n", cache[i]);
    }
    
    return 0;
}
