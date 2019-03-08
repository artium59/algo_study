#include <iostream>
#include <cstring>
#include <queue>

const int xrr[4] = { 1, -1, 0, 0 }, yrr[4] = { 0, 0, 1, -1 };
int m, n, cnt = 0, tomato[1000][1000];
bool visited[1000][1000];
std::queue<std::pair<int, int>> q;

int BFS() {
    int x, y, nx, ny, day;

    while (!q.empty()) {
        y = q.front().first;
        x = q.front().second;
        day = tomato[y][x];
        q.pop();

        if (visited[y][x]) continue;
        visited[y][x] = true; cnt--;

        for (int i = 0; i < 4; i++) {
            ny = y + yrr[i]; nx = x + xrr[i];
            if (-1<ny && ny<n && -1<nx && nx<m && !visited[ny][nx] && tomato[ny][nx] == 0) {
                tomato[ny][nx] = day+1;
                q.push(std::make_pair(ny, nx));
            }
        }
    }

    if (cnt != 0) day = 0;

    return day;
}

int main() {
    memset(visited, false, sizeof(visited));

    scanf("%d %d", &m, &n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &tomato[i][j]);
            if (tomato[i][j] == 1) q.push(std::make_pair(i, j));
            if (tomato[i][j] != -1) cnt++;
        }
    }

    printf("%d", BFS()-1);

    return 0;
}
