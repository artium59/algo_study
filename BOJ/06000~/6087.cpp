#include <cstdio>
#include <queue>
#include <tuple>
using namespace std;

const int yrr[] {-1,1,0,0}, xrr[] {0,0,-1,1};
int w, h, x, y, dir, dx, dy, cnt, ans=1e9;
char chart[100][100];
int visited[100][100][4];
queue<tuple<int, int, int, int>> q;

int main() {
    scanf("%d %d", &w, &h);
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            for (int k = 0; k < 4; ++k)
                visited[i][j][k] = 1e9;

            scanf(" %c", &chart[i][j]);
            if (chart[i][j] == 'C' && q.empty()) {
                q.push({ i, j, 0, 0 });
                q.push({ i, j, 1, 0 });
                q.push({ i, j, 2, 0 });
                q.push({ i, j, 3, 0 });
                chart[i][j] = '*';
            }
        }
    }

    while (!q.empty()) {
        y = get<0>(q.front());
        x = get<1>(q.front());
        dir = get<2>(q.front());
        cnt = get<3>(q.front());
        q.pop();

        if (chart[y][x] == 'C') {
            if (ans > cnt) ans = cnt;
            continue;
        }

        for (int i = 0; i < 4; ++i) {
            if (dir+i == 1 || dir+i == 5) continue;

            dy = y + yrr[i];
            dx = x + xrr[i];

            if (0<=dy&&dy<h && 0<=dx&&dx<w) {
                if (chart[dy][dx] == '*') continue;
                if (visited[dy][dx][i] <= cnt+(dir!=i)) continue;

                visited[dy][dx][i] = cnt+(dir!=i);
                q.push({ dy, dx, i, cnt+(dir!=i) });
            }
        }
    }

    printf("%d", ans);
    return 0;
}
