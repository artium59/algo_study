#include <iostream>
#include <queue>
using namespace std;

const int yrr[] {-1, 1, 0, 0}, xrr[] {0, 0, -1, 1};
int r, c, last_v, last_k;
char field[250][250];

void bfs(int y, int x) {
    int dy, dx, k=0, v=0;
    queue<pair<int, int>> q;

    if (field[y][x] == 'v') ++v;
    else if (field[y][x] == 'k') ++k;

    q.push({ y, x });
    field[y][x] = '#';

    while (!q.empty()) {
        y = q.front().first;
        x = q.front().second;
        q.pop();

        for (int i = 0; i < 4; ++i) {
            dy = y + yrr[i];
            dx = x + xrr[i];

            if (0<=dy&&dy<r && 0<=dx&&dx<c) {
                if (field[dy][dx] == '#') continue;

                if (field[dy][dx] == 'v') ++v;
                else if (field[dy][dx] == 'k') ++k;

                field[dy][dx] = '#';
                q.push({ dy, dx });
            }
        }
    }

    if (k > v) last_k += k;
    else last_v += v;
}

int main() {
    scanf("%d %d", &r, &c);
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j)
            scanf(" %c", &field[i][j]);
    }

    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            if (field[i][j] != '#') bfs(i, j);
        }
    }

    printf("%d %d", last_k, last_v);
    return 0;
}
