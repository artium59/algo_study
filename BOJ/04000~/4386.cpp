#include <cstdio>
#include <cmath>
#include <queue>
#include <vector>
using namespace std;

int n, cnt, cur;
float x, y, ans;
bool visited[100];
vector<pair<float, float>> stars;
priority_queue<pair<float, int>> pq;

inline float dist(int i, int j) {
    return sqrt(pow(stars[i].first-stars[j].first, 2) + pow(stars[i].second-stars[j].second, 2));
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%f %f", &x, &y);
        stars.push_back({ x, y });
    }

    visited[0] = true;
    for (int i = 1; i < n; ++i)
        pq.push({ -dist(0, i), i });

    while (!pq.empty() && cnt < n-1) {
        y = -pq.top().first;
        cur = pq.top().second;
        pq.pop();

        if (visited[cur]) continue;
        visited[cur] = true;

        ans += y;
        ++cnt;

        for (int i = 1; i < n; ++i) {
            if (visited[i]) continue;
            pq.push({ -dist(cur, i), i });
        }
    }

    printf("%.2f", ans);
    return 0;
}
