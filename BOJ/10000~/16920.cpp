#include <iostream>
#include <functional>
#include <queue>
using namespace std;

const int yrr[] {-1,1,0,0}, xrr[] {0,0,-1,1}, MAX=510000;
int n, m, p, s, x, y, dx, dy, walk[10], ans[10], cnt;
string grid[1000];
queue<pair<int, int>> q[10];

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    function<void(int)> bfs = [](int num) {
        for (int a = 0; a < walk[num]; ++a) {
            s = q[num].size();
            if (s == 0) break;
            for (int b = 0; b < s; ++b) {
                y = q[num].front().first;
                x = q[num].front().second;
                q[num].pop();

                for (int i = 0; i < 4; ++i) {
                    dy = y + yrr[i];
                    dx = x + xrr[i];

                    if (0<=dy&&dy<n && 0<=dx&&dx<m) {
                        if (grid[dy][dx] != '.') continue;
                        ++ans[num];
                        grid[dy][dx] = num+'0';
                        q[num].push({ dy, dx });
                    }
                }
            }
        }
    };

    cin >> n >> m >> p;
    for (int i = 1; i <= p; ++i) {
        cin >> walk[i];
        walk[i] = min(walk[i], MAX);
    }
    for (int i = 0; i < n; ++i) {
        cin >> grid[i];
        for (int j = 0; j < m; ++j) {
            if ('0' < grid[i][j] && grid[i][j] <= '9') {
                ++cnt; ++ans[grid[i][j]-'0'];
                q[grid[i][j]-'0'].push({ i, j });
            }
        }
    }

    while (cnt > 0) {
        cnt = 0;
        for (int i = 1; i <= p; ++i) {
            bfs(i);
            cnt += q[i].size();
        }
    }

    for (int i = 1; i <= p; ++i)
        cout << ans[i] << ' ';

    return 0;
}
