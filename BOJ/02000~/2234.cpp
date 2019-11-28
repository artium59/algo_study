#include <cstdio>
#include <cstring>
#include <queue>

const int wall[]={1,2,4,8}, xrr[]={-1,0,1,0}, yrr[]={0,-1,0,1};
int n, m, c, big, room[50][50], num[50][50], cnt[2500];
bool visited[50][50];

inline int max(int a, int b) { return a > b ? a : b; }

void bfs(int b, int a, int color) {
    int x, y, nx, ny, bulk=0;
    std::queue<std::pair<int, int>> q;

    q.push({ b, a });
    visited[b][a] = true;
    while (!q.empty()) {
        y = q.front().first;
        x = q.front().second;
        q.pop();
        num[y][x] = color;
        ++bulk;

        for (int i = 0; i < 4; ++i) {
            if (room[y][x] & wall[i]) continue;

            ny = y + yrr[i]; nx = x + xrr[i];
            if (visited[ny][nx]) continue;
            visited[ny][nx] = true;
            q.push({ny, nx});
        }
    }

    cnt[c] = bulk;
    big = max(big, bulk);
}

void search(int b, int a) {
    int x, y, nx, ny;
    std::queue<std::pair<int, int>> q;

    q.push({ b, a });
    visited[b][a] = true;
    while (!q.empty()) {
        y = q.front().first;
        x = q.front().second;
        q.pop();

        for (int i = 0; i < 4; ++i) {
            ny = y + yrr[i]; nx = x + xrr[i];
            if (num[b][a] != num[ny][nx]) {
                big = max(big, cnt[num[b][a]] + cnt[num[ny][nx]]);
                continue;
            }

            if (visited[ny][nx]) continue;
            visited[ny][nx] = true;
            q.push({ny, nx});
        }
    }
}

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j)
            scanf("%d", &room[i][j]);
    }

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (!visited[i][j]) ++c, bfs(i, j, c);
        }
    }
    printf("%d\n%d\n", c, big);

    memset(visited, false, sizeof(visited));
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (!visited[i][j]) search(i, j);
        }
    }
    printf("%d", big);

    return 0;
}
