#include <cstdio>
#include <algorithm>
#include <functional>
#include <tuple>
#include <vector>
using namespace std;

int n, m, k, r, c, s, ans=1e9, tmp, arr[51][51], grid[51][51];
vector<tuple<int, int, int>> vec;

int main() {
    scanf("%d %d %d", &n, &m, &k);
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j)
            scanf("%d", &grid[i][j]);
    }
    for (int i = 0; i < k; ++i) {
        scanf("%d %d %d", &r, &c, &s);
        vec.push_back({ r, c, s });
    }
    sort(vec.begin(), vec.end());

    function<void(int, int, int)> rotate = [](int r, int c, int s) {
        for (int a = 0; a < s; ++a) {
            tmp = arr[r-s+a][c+s-a];

            for (int j = c+s-a; j > c-s+a ; --j)
                arr[r-s+a][j] = arr[r-s+a][j-1];

            for (int i = r-s+a; i < r+s-a; ++i)
                arr[i][c-s+a] = arr[i+1][c-s+a];

            for (int j = c-s+a; j < c+s-a ; ++j)
                arr[r+s-a][j] = arr[r+s-a][j+1];

            for (int i = r+s-a; i > r-s+a; --i)
                arr[i][c+s-a] = arr[i-1][c+s-a];
            arr[r-s+a+1][c+s-a] = tmp;
        }
    };

    do {
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j)
                arr[i][j] = grid[i][j];
        }

        for (const auto& v : vec)
            rotate(get<0>(v), get<1>(v), get<2>(v));

        for (int i = 1; i <= n; ++i) {
            tmp = 0;
            for (int j = 1; j <= m; ++j)
                tmp += arr[i][j];
            ans = min(ans, tmp);
        }

    } while (next_permutation(vec.begin(), vec. end()));

    printf("%d", ans);

    return 0;
}
