#include <cstdio>
#include <functional>
#include <queue>
#include <tuple>
using namespace std;

const int xrr[] {-1,-1,-1,0,0,1,1,1}, yrr[] {-1,0,1,-1,1,-1,0,1};
int h, w, x, y, dx, dy, ans;
char sand[1000][1000];
queue<tuple<int, int, int>> q;

int main() {
    function<void()> bfs = []() {
        ans = 0;
        while (!q.empty()) {
            y = get<0>(q.front());
            x = get<1>(q.front());
            ans = get<2>(q.front());
            q.pop();

            for (int i = 0; i < 8; ++i) {
                dy = y + yrr[i];
                dx = x + xrr[i];

                if (0<=dy&&dy<h && 0<=dx&&dx<w) {
                    if ('1' <= sand[dy][dx] && sand[dy][dx] <= '9') {
                        if (--sand[dy][dx] == '0')
                            q.push(make_tuple(dy, dx, ans+1));
                    }
                }
            }
        }
    };

    scanf("%d %d", &h, &w);
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            scanf(" %c", &sand[i][j]);
            if (sand[i][j] == '.') q.push(make_tuple(i, j, 0));
        }
    }
    bfs();
    printf("%d", ans);

    return 0;
}
