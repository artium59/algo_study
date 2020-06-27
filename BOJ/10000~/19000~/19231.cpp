#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

const int MAX = 100000;
int n, m, q, k, a, b, cnt, s, cur, ans[MAX];
bool visited[MAX];
vector<int> graph[MAX];
queue<int> que;

void bfs(int day) {
    for (int r = 0; r < day*k; ++r) {
        s = que.size();

        for (int j = 0; j < s; ++j) {
            cur = que.front();
            que.pop();

            for (const auto& g : graph[cur]) {
                if (visited[g]) continue;

                ++cnt;
                que.push(g);
                visited[g] = true;
                ans[g] = day;
            }
        }
    }
}

int main() {
    scanf("%d %d %d %d", &n, &m, &q, &k);
    for (int i = 0; i < q; ++i) {
        scanf("%d", &a);
        ++cnt;
        que.push(a-1);
        visited[a-1] = true;
    }

    for (int i = 0; i < m; ++i) {
        scanf("%d %d", &a, &b);
        graph[a-1].push_back(b-1);
        graph[b-1].push_back(a-1);
    }

    for (int i = 0; cnt != n; ++i)
        bfs(i+1);

    for (int i = 0; i < n; ++i)
        printf("%d ", ans[i]);

    return 0;
}
