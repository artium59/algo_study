#include <iostream>
#include <queue>
using namespace std;

const int xrr[4] = { 1, -1, 0, 0 }, yrr[4] = { 0, 0, 1, -1 };
int r, c, wolf = 0, sheep = 0;
char map[250][250];
bool visited[250][250];

void Init() {
    for (int i = 0; i < 250; i++) {
        for (int j = 0; j <250; j++)
            visited[i][j] = false;
    }
}

void BFS(int b, int a) {
    int x, y, nx, ny, v = 0, o = 0;
    queue<pair<int, int>> q;

    q.push(make_pair(b, a));
    while (!q.empty()) {
        y = q.front().first;
        x = q.front().second;
        q.pop();

        if (visited[y][x]) continue;
        visited[y][x] = true;

        if (map[y][x] != '.') {
            if (map[y][x] == 'v') v++;
            else o++;
    }

        for (int i = 0; i < 4; i++) {
            ny = y + yrr[i];
            nx = x + xrr[i];

            if (-1<ny&&ny<r && -1<nx&&nx<c && !visited[ny][nx] && map[ny][nx]!='#')
                q.push(make_pair(ny, nx));
        }
    }

    if (v >= o) wolf += v;
    else sheep += o;
}

int main() {
    scanf("%d %d", &r, &c);
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            scanf(" %c", &map[i][j]);
        }
    }

    Init();
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (map[i][j] != '#' && !visited[i][j])
                BFS(i, j);
        }
    }

    printf("%d %d", sheep, wolf);

    return 0;
}
