#include <bits/stdc++.h>
using namespace std;

const int xrr[] {-1,1,0,0}, yrr[] {0,0,1,-1};
int n, m, x, y, two, zero, tmp, dx, dy, ret, cnt, ans=1e9, grid[50][50];
bool check[10], visited[50][50];
vector<pair<int, int>> vec;

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            scanf("%d", &grid[i][j]);
            if (grid[i][j] == 2) {
                ++two;
                vec.push_back({ i, j });
            }
            else if (grid[i][j] == 0) ++zero;
        }
    }
    for (int i = 0; i < m; ++i) check[i] = true;

    function<void()> bfs = []() {
        std::queue<tuple<int, int, int>> q;
        for (int i = 0; i < two; ++i) {
            if (check[i])
                q.push({ vec[i].first, vec[i].second, 0 });
        }

        while (!q.empty()) {
            y = get<0>(q.front());
            x = get<1>(q.front());
            cnt = get<2>(q.front());
            q.pop();

            if (grid[y][x] == 0) ret = max(ret, cnt);
            for (int i = 0; i < 4; ++i) {
                dy = y+yrr[i]; dx = x+xrr[i];

                if (0<=dy&&dy<n && 0<=dx&&dx<n && grid[dy][dx] != 1) {
                    if (visited[dy][dx]) continue;

                    if (grid[dy][dx] == 0) --tmp;
                    visited[dy][dx] = true;
                    q.push({ dy, dx, cnt+1 });
                }
            }
        }

        if (tmp == 0) ans = min(ans, ret);
    };
    
    do {
        memset(visited, false, sizeof(visited));
        ret = 0; tmp = zero;
        bfs();
    } while(prev_permutation(check, check+two));

    if (ans == 1e9) ans = -1;
    printf("%d", ans);

    return 0;
}
