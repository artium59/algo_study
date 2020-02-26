#include <iostream>
#include <functional>
#include <queue>
using namespace std;

const int rrr[] {-1,1,0,0}, crr[] {0,0,1,-1};
int n, m, h, w, sr, sc, fr, fc, dr, dc, size, ans;
int grid[1002][1002];
bool visited[1002][1002];
queue<pair<int, int>> q;

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            scanf("%d", &grid[i][j]);
            grid[i][j] = (grid[i][j] == 0);
            grid[i][j] += grid[i-1][j] + grid[i][j-1] - grid[i-1][j-1];
        }
    }
    scanf("%d %d %d %d %d %d", &h, &w, &sr, &sc, &fr, &fc);

    function<bool(int, int, int, int)> check = [](int a, int b, int c, int d) {
        if (1<=a && c<=n && 1<=b && d<=m) {
            if (grid[c][d] - grid[a-1][d] - grid[c][b-1] + grid[a-1][b-1] == h*w)
                return true;
            else
                return false;
        }
        return false;
    };

    q.push({ sr, sc });
    while (true) {
        size = q.size();
        if (size == 0) { ans = 1e9; break; }

        for (int i = 0; i < size; ++i) {
            sr = q.front().first;
            sc = q.front().second;
            q.pop();

            if (sr == fr && sc == fc)
                goto ANS;

            for (int i = 0; i < 4; ++i) {
                dr = sr + rrr[i];
                dc = sc + crr[i];

                if (check(dr, dc, dr+h-1, dc+w-1) && !visited[dr][dc]) {
                    visited[dr][dc] = true;
                    q.push({ dr, dc });
                }
            }
        }

        ++ans;
    }

    ANS:
    if (ans == 1e9) ans = -1;
    printf("%d", ans);

    return 0;
}
