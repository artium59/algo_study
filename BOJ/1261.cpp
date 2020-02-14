#include <iostream>
#include <queue>
#include <tuple>
using namespace std;

const int yrr[] {-1,1,0,0}, xrr[] {0,0,1,-1};
int n, m, ans=1234567890, maze[100][100];
int visited[100][100];

void bfs() {
    int x, y, dy, dx, cnt;
    queue<tuple<int, int, int>> q;

    q.push({ 0, 0, 0 });
    while (!q.empty()) {
        y = get<0>(q.front());
        x = get<1>(q.front());
        cnt = get<2>(q.front());
        q.pop();

        for (int i = 0; i < 4; i++) {
            dy = y+yrr[i]; dx = x + xrr[i];

            if (0<=dy&&dy<n && 0<=dx&&dx<m) {
                if (visited[dy][dx] <= cnt+maze[dy][dx]) continue;

                visited[dy][dx] = cnt+maze[dy][dx];
                q.push({ dy, dx, cnt+maze[dy][dx] });
            }
        }
    }
}

int main() {
    scanf("%d %d", &m, &n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%1d", &maze[i][j]);
            visited[i][j] = 123456789;
        }
    }

    visited[0][0] = 0;
    bfs();
    printf("%d", visited[n-1][m-1]);

    return 0;
}
