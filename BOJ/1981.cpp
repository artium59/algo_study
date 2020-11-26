#include <cstdio>
#include <cstring>
#include <queue>
#include <tuple>
using namespace std;

const int xrr[4] = {-1,1,0,0}, yrr[4] = {0,0,-1,1};
int n, l, m, r=200, arr[100][100];
bool visited[100][100];

inline bool boundary(int y, int x) {
    return 0<=y&&y<n && 0<=x&&x<n;
}

bool bfs() {
    int x, y, dx, dy;

    for (int s = max(0, arr[0][0]-m); s <= min(200, arr[0][0]+m); ++s) {
        memset(visited, true, sizeof(visited));

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (s <= arr[i][j] && arr[i][j] <= s+m)
                    visited[i][j] = false;
            }
        }
        if (visited[0][0]) continue;

        queue<pair<int, int>> q;
        q.push({ 0, 0 });

        while (!q.empty()) {
            y = q.front().first;
            x = q.front().second;
            q.pop();

            if (y == n-1 && x == n-1) return true;

            for (int k = 0; k < 4; ++k) {
                dy = y + yrr[k];
                dx = x + xrr[k];

                if (!boundary(dy, dx)) continue;
                if (visited[dy][dx]) continue;

                visited[dy][dx] = true;
                q.push({ dy, dx });
            }
        }
    }

    return false;
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j)
            scanf("%d", &arr[i][j]);
    }

    while (l <= r) {
        m = (l+r) / 2;

        if (bfs()) r = m-1;
        else l = m+1;
    }

    printf("%d", r+1);
    return 0;
}
