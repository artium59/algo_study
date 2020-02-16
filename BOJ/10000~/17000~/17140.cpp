#include <iostream>
#include <cstring>
#include <algorithm>
#include <functional>
#include <vector>
using namespace std;

int r, c, k, r_cnt=3, c_cnt=3, ans, grid[100][100];
int cnt_arr[101];

int main() {
    scanf("%d %d %d", &r, &c, &k); --r; --c;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j)
            scanf("%d", &grid[i][j]);
    }

    function<int()> row_calc = []() {
        int ret = 0;

        for (int i = 0; i < r_cnt; ++i) {
            memset(cnt_arr, 0, sizeof(cnt_arr));
            vector<pair<int, int>> vec;

            for (int j = 0; j < 100; ++j)
                ++cnt_arr[grid[i][j]];
            for (int j = 1; j < 101; ++j) {
                if (cnt_arr[j] > 0) vec.push_back({ cnt_arr[j], j });
            }
            sort(vec.begin(), vec.end());

            for (int j = 0; j/2 < vec.size(); j+=2) {
                grid[i][j] = vec[j/2].second;
                grid[i][j+1] = vec[j/2].first;
            }
            for (int j = vec.size()*2; j < 100; ++j) grid[i][j] = 0;

            ret = max(ret, (int)vec.size()*2);
        }

        return ret;
    };

    function<int()> col_calc = []() {
        int ret = 0;

        for (int j = 0; j < c_cnt; ++j) {
            memset(cnt_arr, 0, sizeof(cnt_arr));
            vector<pair<int, int>> vec;

            for (int i = 0; i < 100; ++i)
                ++cnt_arr[grid[i][j]];
            for (int i = 1; i < 101; ++i) {
                if (cnt_arr[i] > 0) vec.push_back({ cnt_arr[i], i });
            }
            sort(vec.begin(), vec.end());

            for (int i = 0; i/2 < vec.size(); i+=2) {
                grid[i][j] = vec[i/2].second;
                grid[i+1][j] = vec[i/2].first;
            }
            for (int i = vec.size()*2; i < 100; ++i) grid[i][j] = 0;

            ret = max(ret, (int)vec.size()*2);
        }

        return ret;
    };

    while (grid[r][c] != k) {
        if (ans > 100) { ans = -1; break; }

        if (r_cnt >= c_cnt) c_cnt = row_calc();
        else r_cnt = col_calc();

        ++ans;
    }

    printf("%d", ans);

    return 0;
}
