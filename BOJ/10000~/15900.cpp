#include <iostream>
#include <queue>
#include <vector>

const int MAX = 500000;
int ans = 0;
bool visited[MAX];
std::vector<int> graph[MAX];

void BFS() {
    int cur, dist, cnt;
    std::queue<std::pair<int, int>> q;
    q.push(std::make_pair(0, 0));

    while (!q.empty()) {
        cnt = 0;
        cur = q.front().first;
        dist = q.front().second;
        q.pop();

        if (visited[cur]) continue;
        visited[cur] = true;

        for (const auto& g : graph[cur]) {
            if (!visited[g]) q.push(std::make_pair(g, dist+1));
            else cnt++;
        }

        if (cnt == graph[cur].size()) ans = (ans + dist) % 2;
    }
}

int main() {
    int n, a, b;

    scanf("%d", &n);
    for (int i = 0; i < n-1; i++) {
        scanf("%d %d", &a, &b);
        graph[a-1].push_back(b-1);
        graph[b-1].push_back(a-1);
    }

    for (int i = 0; i < MAX; i++)
        visited[i] = false;

    BFS();
    printf(ans == 1 ? "Yes" : "No");

    return 0;
}
