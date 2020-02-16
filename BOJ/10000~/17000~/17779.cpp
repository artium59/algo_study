#include <cstdio>
#include <cstring>
#include <functional>
using namespace std;

int n, ans=1e9, city[22][22];
bool bound[22][22], visited[22][22];

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j)
            scanf("%d", &city[i][j]);
    }

    function<int(int, int, int, int)> calc = [](int x, int y, int d1, int d2) {
        int one=0, two=0, three=0, four=0, five=0, big=0, small=1e9;

        for (int r = 1; r < x+d1; ++r) {
            for (int c = 1; c <= y; ++c) {
                if (bound[r][c]) break;
                visited[r][c] = true;
                one += city[r][c];
            }
        }

        for (int r = 1; r <= x+d2; ++r) {
            for (int c = n; c > y; --c) {
                if (bound[r][c]) break;
                visited[r][c] = true;
                two += city[r][c];
            }
        }

        for (int r = x+d1; r <= n; ++r) {
            for (int c = 1; c < y-d1+d2; ++c) {
                if (bound[r][c]) break;
                visited[r][c] = true;
                three += city[r][c];
            }
        }

        for (int r = x+d2+1; r <= n; ++r) {
            for (int c = n; c >= y-d1+d2; --c) {
                if (bound[r][c]) break;
                visited[r][c] = true;
                four += city[r][c];
            }
        }

        for (int r = 1; r <= n; ++r) {
            for (int c = 1; c <= n; ++c) {
                if (visited[r][c]) continue;
                five += city[r][c];
            }
        }

        big = max(max(five, max(big, one)), max(four, max(two, three)));
        small = min(min(five, min(big, one)), min(four, min(two, three)));

        return big-small;
    };

    for (int x = 1; x <= n; ++x) {
        for (int y = 1; y <= n; ++y) {
            for (int d1 = 1; d1 < n; ++d1) {
                for (int d2 = 1; x+d1+d2<=n && 1<=y-d1&&y-d1 && y+d2<=n; ++d2) {
                    memset(bound, false, sizeof(bound));

                    for (int i = 0; i <= d1; ++i) {
                        bound[x+i][y-i] = true;
                        bound[x+d2+i][y+d2-i] = true;
                    }
                    for (int i = 0; i <= d2; ++i) {
                        bound[x+i][y+i] = true;
                        bound[x+d1+i][y-d1+i] = true;
                    }

                    memset(visited, false, sizeof(visited));
                    ans = min(ans, calc(x, y, d1, d2));
                }
            }
        }
    }

    printf("%d", ans);

    return 0;
}
