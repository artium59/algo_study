#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>
#include <tuple>
using namespace std;

const int xrr[] {1,-1,0,0,0,0}, yrr[] {0,0,1,-1,0,0}, zrr[] {0,0,0,0,1,-1};
int ans = 1e9, x, y, z, dx, dy, dz, cnt, arr[5] = {0,1,2,3,4};
bool input_maze[5][5][5], maze[5][5][5], visited[5][5][5];

void rotate(int layer) {
    bool temp[5][5];

    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j)
            temp[4-j][i] = maze[layer][i][j];
    }

    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j)
            maze[layer][i][j] = temp[i][j];
    }
}

int bfs() {
    queue<tuple<int, int, int, int>> q;

    memset(visited, false, sizeof(visited));
    q.push({ 0, 0, 0, 0 });
    visited[0][0][0] = true;

    while (!q.empty()) {
        z = get<0>(q.front());
        y = get<1>(q.front());
        x = get<2>(q.front());
        cnt = get<3>(q.front());
        q.pop();

        if (z == 4 && y == 4 && x == 4) return cnt;

        for (int i = 0; i < 6; ++i) {
            dz = z + zrr[i];
            dy = y + yrr[i];
            dx = x + xrr[i];

            if (0<=dz&&dz<5 && 0<=dy&&dy<5 && 0<=dx&&dx<5) {
                if (visited[dz][dy][dx] || !maze[dz][dy][dx]) continue;

                visited[dz][dy][dx] = true;
                q.push({ dz, dy, dx, cnt+1 });
            }
        }
    }

    return 1e9;
}

int main() {
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            for (int k = 0; k < 5; ++k)
                scanf("%d", &input_maze[i][j][k]);
        }
    }

    do {
        for (int i = 0; i < 5; ++i) {
            for (int j = 0; j < 5; ++j) {
                for (int k = 0; k < 5; ++k)
                    maze[i][j][k] = input_maze[arr[i]][j][k];
            }
        }

        for (int a = 0; a < 4; ++a) {
            rotate(0);
            for (int b = 0; b < 4; ++b) {
                rotate(1);
                for (int c = 0; c < 4; ++c) {
                    rotate(2);
                    for (int d = 0; d < 4; ++d) {
                        rotate(3);
                        for (int e = 0; e < 4; ++e) {
                            rotate(4);

                            if (maze[0][0][0] && maze[4][4][4]) {
                                cnt = bfs();

                                ans = ans < cnt ? ans : cnt;
                            }
                        }
                    }
                }
            }
        }

        if (ans == 12) break;

    } while (next_permutation(arr, arr+5));

    if (ans == 1e9) ans = -1;
    printf("%d", ans);

    return 0;
}
