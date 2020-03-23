#include <iostream>
#include <functional>
#include <queue>
using namespace std;

const int yrr[] {-1,1,0,0}, xrr[] {0,0,-1,1};
int n, m, t = 1, cnt[1000001], visited[1002][1002];
char maze[1002][1002];
queue<pair<int, int>> q;

int main() {
    function<int(int, int)> sum = [](int y, int x) {
        int ret = 0, arr[] {-1,-1,-1,-1};

        for (int i = 0; i < 4; ++i) {
            for (int k = 0; k < 4; ++k) {
                if (arr[k] == visited[y+yrr[i]][x+xrr[i]]) break;

                if (arr[k] == -1) {
                    arr[k] = visited[y+yrr[i]][x+xrr[i]];
                    ret += cnt[visited[y+yrr[i]][x+xrr[i]]];
                    break;
                }
            }
        }

        return ret;
    };

    function<int(int, int, int)> bfs = [](int y, int x, int color) {
        int dy, dx, ret = 0;

        q.push({ y, x });
        visited[y][x] = color;

        while (!q.empty()) {
            y = q.front().first;
            x = q.front().second;
            q.pop();
            ++ret;

            for (int i = 0; i < 4; ++i) {
                dy = y + yrr[i];
                dx = x + xrr[i];

                if (dy <= 0 || dy > n || dx <= 0 || dx > m) continue;
                if (visited[dy][dx] || maze[dy][dx] != '0') continue;
                visited[dy][dx] = color;
                q.push({ dy, dx });
            }
        }

        return ret;
    };

    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j)
            scanf(" %c", &maze[i][j]);
    }

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (maze[i][j] == '0') {
                if (visited[i][j]) continue;
                cnt[t] = bfs(i, j, t); ++t;
            }
        }
    }

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j)
            printf("%d", maze[i][j] != '0' ? (sum(i, j)+1)%10 : maze[i][j]-'0');
        printf("\n");
    }

    return 0;
}
