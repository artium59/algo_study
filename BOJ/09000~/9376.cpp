#include <iostream>
#include <cstring>
#include <functional>
#include <queue>
using namespace std;

const int yrr[] {-1,1,0,0}, xrr[] {0,0,-1,1};
const int MAX = 1e9+9;
int tc, h, w, tmp, aa, ans;
char prison[102][102];
int visited[102][102][3];
pair<int, int> people[3];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    function<void(pair<int, int>, int)> bfs = [](const auto& p, int z) {
        int y, x, cnt, dy, dx;
        deque<tuple<int, int, int>> q;

        q.push_back({ p.first, p.second, 0 });
        while (!q.empty()) {
            y = get<0>(q.front());
            x = get<1>(q.front());
            cnt = get<2>(q.front());
            q.pop_front();

            for (int i = 0; i < 4; ++i) {
                dy = y + yrr[i];
                dx = x + xrr[i];

                if (dy < 0 || dy > h+1 || dx < 0 || dx > w+1) continue;
                if (prison[dy][dx] == '*') continue;
                if (visited[dy][dx][z] != -1) continue;
                visited[dy][dx][z] = cnt;

                if (prison[dy][dx] == '.') q.push_front({ dy, dx, cnt });
                else ++visited[dy][dx][z], q.push_back({ dy, dx, cnt+1 });
            }
        }
    };

    cin >> tc;
    while (tc--) {
        aa = 1; ans = MAX;
        memset(visited, -1, sizeof(visited));

        cin >> h >> w;
        for (int i = 1; i <= h; ++i) {
            for (int j = 1; j <= w; ++j) {
                cin >> prison[i][j];
                if (prison[i][j] == '$') {
                    prison[i][j] = '.';
                    people[aa++] = { i, j };
                }
            }
        }
        for (int i = 0; i < h+2; ++i)
            prison[i][0] = prison[i][w+1] = '.';
        for (int j = 0; j < w+2; ++j)
            prison[0][j] = prison[h+1][j] = '.';

        for (int i = 0; i < 3; ++i)
            bfs(people[i], i);

        for (int i = 1; i <= h; ++i) {
            for (int j = 1; j <= w; ++j) {
                if (prison[i][j] == '*') continue;

                tmp = prison[i][j] == '#' ? -2 : 0;
                for (int k = 0; k < 3; ++k)
                tmp += visited[i][j][k];

                ans = min(ans, tmp);
            }
        }

        cout << ans << '\n';
    }

    return 0;
}
