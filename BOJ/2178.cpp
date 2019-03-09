#include <stdio.h>
#include <cstring>
#include <tuple>
#include <queue>

const int xrr[4] = { 1, -1, 0, 0 }, yrr[4] = { 0, 0, 1, -1 };
int n, m;
bool maze[100][100], visited[100][100];

int BFS() {
    int x, y, nx, ny, dist;
    std::queue<std::tuple<int, int, int>> q;
    q.push(std::make_tuple(0, 0, 1));
	
    while (!q.empty()) {
        y = std::get<0>(q.front());
        x = std::get<1>(q.front());
        dist = std::get<2>(q.front());
        q.pop();

        if (y == n-1 && x == m-1) break;

        if (visited[y][x]) continue;
        visited[y][x] = true;

        for (int i = 0; i < 4; i++) {
            ny = y + yrr[i]; nx = x + xrr[i];
            if (-1 < ny && ny < n && -1 < nx && nx < m && !visited[ny][nx] && maze[ny][nx])
                q.push(std::make_tuple(ny, nx, dist+1));
        }
    }

    return dist;
}

int main() {
    char ch;

    memset(visited, false, sizeof(visited));

    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf(" %c", &ch);
            maze[i][j] = (ch == '1');
        }
    }

    printf("%d", BFS());

    return 0;
}