#include <bits/stdc++.h>
using namespace std;

const int xrr[] {-1,1,0,0}, yrr[] {0,0,-1,1};
int n, m, x, y, dx, dy, cnt, key, ans=1e9;
char maze[50][50];
bool visited[50][50][1<<6];
queue<tuple<int, int, int, int>> q;

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            scanf(" %c", &maze[i][j]);
            if (maze[i][j] == '0') {
                q.push({ i, j, 0, 0 });
                visited[i][j][0] = true;
            }
        }
    }

    while (!q.empty()) {
        y = get<0>(q.front());
        x = get<1>(q.front());
        cnt = get<2>(q.front());
        key = get<3>(q.front());
        q.pop();

        if (maze[y][x] == '1') {
            ans = ans < cnt ? ans : cnt;
            break;
        }

        for (int i = 0; i < 4; ++i) {
            dy = y + yrr[i];
            dx = x + xrr[i];

            if (0<=dy&&dy<n && 0<=dx&&dx<m && !visited[dy][dx][key]) {
                visited[dy][dx][key] = true;

                if (maze[dy][dx] == '#') continue;
                else if ('A' <= maze[dy][dx] && maze[dy][dx] <= 'F') {
                    if ((key & (1<<(maze[dy][dx]-'A'))) != 0)
                        q.push({ dy, dx, cnt+1, key });
                }
                else if ('a' <= maze[dy][dx] && maze[dy][dx] <= 'f')
                    q.push({ dy, dx, cnt+1, key|(1<<(maze[dy][dx]-'a')) });
                else
                    q.push({ dy, dx, cnt+1, key });
            }
        }
    }

    if (ans == 1e9) ans = -1;
    printf("%d", ans);

    return 0;
}
