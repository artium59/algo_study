#include <iostream>
#include <cstring>
#include <queue>
#include <vector>

int n, max_dist, a, b, c;
bool visited[10000];
std::vector<std::pair<int, int>> tree[10000];

void BFS(int start) {
    int cur, dist;
    std::queue<std::pair<int, int>> q;

    q.push({ start, 0 });
    while (!q.empty()) {
        cur = q.front().first;
        dist = q.front().second;
        q.pop();

        if (max_dist < dist) max_dist = dist, a = cur;

        for (const auto& t : tree[cur]) {
            if (visited[t.first]) continue;
            visited[t.first] = true;
            q.push({ t.first, dist+t.second });
        }
    }
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d %d", &a, &b, &c);
        tree[a-1].push_back({ b-1, c });
        tree[b-1].push_back({ a-1, c });
    }

    BFS(0);
    memset(visited, false, sizeof(visited));
    BFS(a);

    printf("%d", max_dist);

    return 0;
}
