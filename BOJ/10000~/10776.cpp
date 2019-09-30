#include <cstdio>
#include <queue>
#include <tuple>
#include <vector>
using namespace std;

int k, n, m, a, b, ti, hi, arrive[2000][201];
vector<tuple<int, int, int>> islands[2000];

int Dijkstra() {
    int ret = -1;
    priority_queue<tuple<int, int, int>> pq;

    pq.push({ 0, k, a });
    while (!pq.empty()) {
        ti = get<0>(pq.top());
        hi = get<1>(pq.top());
        m = get<2>(pq.top());
        pq.pop();

        if (m == b) { ret = -ti; break; }

        for (const auto& i : islands[m]) {
            if (hi - get<2>(i) <= 0) continue;
            if (arrive[get<0>(i)][hi - get<2>(i)] &&
                arrive[get<0>(i)][hi - get<2>(i)] < -ti + get<1>(i)) continue;

            arrive[get<0>(i)][hi - get<2>(i)] = -ti + get<1>(i);
            pq.push({ ti - get<1>(i), hi - get<2>(i), get<0>(i) });
        }
    }

    return ret;
}

int main() {
    scanf("%d %d %d", &k, &n, &m);
    while (m--) {
        scanf("%d %d %d %d", &a, &b, &ti, &hi);

        islands[a - 1].push_back({ b - 1, ti, hi });
        islands[b - 1].push_back({ a - 1, ti, hi });
    }
    scanf("%d %d", &a, &b); a--; b--;
    printf("%d", Dijkstra());

    return 0;
}
