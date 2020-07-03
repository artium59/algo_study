#include <iostream>
#include <tuple>
#include <queue>
using namespace std;

const int xrr[] {-1,1,0,0}, yrr[] {0,0,-1,1};
int n, m, k, t, x, y, dx, dy, dist[1000][1000][11];
bool road[1000][1000];
char ch;
queue<tuple<int, int, int>> q;

int bfs() {
    q.push({ 0, 0, 0 });
    dist[0][0][0] = 1;

    while (!q.empty()) {
        y = get<0>(q.front());
        x = get<1>(q.front());
        t = get<2>(q.front());
        q.pop();

        if (y == n-1 && x == m-1)
            return dist[y][x][t];

        for (int i = 0; i < 4; ++i) {
            dy = y + yrr[i];
            dx = x + xrr[i];

            if (0<=dy&&dy<n && 0<=dx&&dx<m) {
                if (road[dy][dx]) {
                    if (dist[dy][dx][t] != 0) continue;

                    dist[dy][dx][t] = dist[y][x][t] + 1;
                    q.push({ dy, dx, t });
                }
                else {
                    // wall
                    if (t+1 > k) continue;
                    if (dist[dy][dx][t+1] != 0) continue;

                    dist[dy][dx][t+1] = dist[y][x][t] + 1;
                    q.push({ dy, dx, t+1 });
                }
            }
        }
    }

    return -1;
}

int main() {
    scanf("%d %d %d", &n, &m, &k);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            scanf(" %c", &ch);
            road[i][j] = ch == '0';
        }
    }

    printf("%d", bfs());
    return 0;
}
