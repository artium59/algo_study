#include <cstdio>
#include <cstring>
#include <queue>

int tc, n, m, a, b, arr[501], cnt[501];
bool team[501][501], visited[501];
std::queue<int> ans;

void topo(int cur) {
    std::queue<int> q;

    q.push(cur);
    while (!q.empty()) {
        cur = q.front();
        ans.push(cur);
        q.pop();

        for (int i = 1; i <= n; ++i) {
            if (!team[cur][i]) continue;

            team[cur][i] = false;
            if (--cnt[i] == 0) {
                visited[i] = true;
                q.push(i);
            }
        }
    }
}

int main() {
    scanf("%d", &tc);
    while (tc--) {
        scanf("%d", &n);
        for (int i = 1; i <= n; ++i) {
            scanf("%d", arr+i);
            for (int j = 1; j < i; ++j) {
                team[arr[j]][arr[i]] = true;
                ++cnt[arr[i]];
            }
        }
        scanf("%d", &m);
        while (m--) {
            scanf("%d %d", &a, &b);
            team[a][b] = !team[a][b];
            team[b][a] = !team[b][a];

            cnt[a] = team[b][a] ? cnt[a]+1 : cnt[a]-1;
            cnt[b] = team[a][b] ? cnt[b]+1 : cnt[b]-1;
        }

        for (int i = 1; i <= n; ++i) {
            if (cnt[arr[i]] == 0 && !visited[arr[i]]) {
                visited[arr[i]] = true;
                topo(arr[i]);
            }
        }

        if (ans.size() != n) {
            printf("IMPOSSIBLE\n");
            while (!ans.empty()) {
                ans.pop();
            }
        }
        else {
            for (int i = 0; i < n; ++i) {
                printf("%d%c", ans.front(), "\n "[i+1 < n]);
                ans.pop();
            }
        }

        memset(cnt, 0, sizeof(cnt));
        memset(team, false, sizeof(team));
        memset(visited, false, sizeof(visited));
    }

    return 0;
}
