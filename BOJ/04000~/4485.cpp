#include <iostream>
#include <queue>
#include <tuple>
using namespace std;

const int xrr[4] = { 1, -1, 0, 0 }, yrr[4] = { 0, 0, 1, -1 };
int n, t = 1, cave[125][125];
bool visited[125][125];

void Init() {
    for (int i = 0; i < 125; i++) {
        for (int j = 0; j < 125; j++)
            visited[i][j] = false;
    }
}

int Find() {
    int cnt, x, y, nx, ny;
    priority_queue<tuple<int, int, int>> pq;
    pq.push(make_tuple(-cave[0][0], 0, 0));

    while (!pq.empty()) {
        cnt = -get<0>(pq.top());
        y = get<1>(pq.top());
        x = get<2>(pq.top());
        pq.pop();

        if (y == n-1 && x == n-1) break;

        if (visited[y][x]) continue;
        visited[y][x] = true;

        for (int i = 0; i < 4; i++) {
            ny = y + yrr[i];
            nx = x + xrr[i];

            if (-1<ny&&ny<n && -1<nx&&nx<n && !visited[ny][nx])
                pq.push(make_tuple(-cnt-cave[ny][nx], ny, nx));
        }
    }

    return cnt;
}

int main() {
    while (true) {
        scanf("%d", &n);

        if (n == 0) break;
        Init();

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++)
                scanf("%d", &cave[i][j]);
        }

        printf("Problem %d: %d\n", t, Find());
        t++;
    }

    return 0;
}
