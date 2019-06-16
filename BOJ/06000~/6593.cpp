#include <iostream>
#include <queue>
#include <tuple>
using namespace std;

const int zrr[6] = {1, -1, 0, 0, 0, 0}, yrr[6] = {0, 0, 1, -1, 0, 0}, xrr[6] = {0, 0, 0, 0, 1, -1};
int l, r, c, x, y, z, ans;
char ch, room[30][30][30];
bool check;

int BFS() {
    int cnt, nx, ny, nz;
    queue<tuple<int, int, int, int>> q;
    q.push(make_tuple(0, z, y, x));
    room[z][y][x] = '#';

    while (!q.empty()) {
        cnt = get<0>(q.front());
        z = get<1>(q.front());
        y = get<2>(q.front());
        x = get<3>(q.front());
        q.pop();

        for (int t = 0; t < 6; t++) {
            nz = z + zrr[t]; ny = y + yrr[t]; nx = x + xrr[t];

            if (-1<nz&&nz<l && -1<ny&&ny<r && -1<nx&&nx<c && room[nz][ny][nx] != '#') {
                if (room[nz][ny][nx] == 'E') {
                    check = true; goto RET;
                }

                q.push(make_tuple(cnt+1, nz, ny, nx));
                room[nz][ny][nx] = '#';
            }
        }
    }

    RET:
    return cnt+1;
}

int main() {
    while (true) {
        check = false;
        scanf("%d %d %d", &l, &r, &c);

        if (l+r+c == 0) break;

        for (int i = 0; i < l; i++) {
            for (int j = 0; j < r; j++) {
                for (int k = 0; k < c; k++) {
                    scanf(" %c", &room[i][j][k]);
                    if (room[i][j][k] == 'S') { z = i; y = j; x = k; }
                }
            }
        }

        ans = BFS();
        if (check) printf("Escaped in %d minute(s).\n", ans);
        else printf("Trapped!\n");
    }

    return 0;
}
