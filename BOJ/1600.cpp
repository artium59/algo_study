#include <cstdio>
#include <functional>
#include <queue>
using namespace std;

const int xrr[] {1,-1,0,0}, yrr[] {0,0,1,-1};
const int h_xrr[] {-2,-2,-1,-1,1,1,2,2}, h_yrr[] {-1,1,-2,2,-2,2,-1,1};
int k, w, h, ans;
bool grid[200][200], visited[200][200][31];

int main() {
    scanf("%d %d %d", &k, &w, &h);
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            scanf("%d", &ans);
            grid[i][j] = ans == 0;
        }
    }

    ans = 1e9;
    function<void()> bfs = []() {
        int x, y, dx, dy, jump, cnt;
        queue<tuple<int, int, int, int>> q;
        
        q.push({ 0, 0, 0, 0 });
        while (!q.empty()) {
            y = get<0>(q.front());
            x = get<1>(q.front());
            jump = get<2>(q.front());
            cnt = get<3>(q.front());
            q.pop();

            if (y == h-1 && x == w-1) { ans = min(ans, cnt); continue; }

            for (int i = 0; i < 4; ++i) {
                dy = y + yrr[i]; dx = x + xrr[i];

                if (0<=dy&&dy<h && 0<=dx&&dx<w && grid[dy][dx]) {
                    if (visited[dy][dx][jump]) continue;

                    visited[dy][dx][jump] = true;
                    q.push({ dy, dx, jump, cnt+1 });
                }
            }

            for (int i = 0; i < 8 && jump < k; ++i) {
                dy = y + h_yrr[i]; dx = x + h_xrr[i];

                if (0<=dy&&dy<h && 0<=dx&&dx<w && grid[dy][dx]) {
                    if (visited[dy][dx][jump+1]) continue;

                    visited[dy][dx][jump+1] = true;
                    q.push({ dy, dx, jump+1, cnt+1 });
                }
            }
        }
    };

    bfs();
    if (ans == 1e9) ans = -1;
    printf("%d", ans);

    return 0;
}
