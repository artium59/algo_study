#include <iostream>
#include <algorithm>
#include <functional>
#include <queue>
#include <tuple>
#include <vector>
using namespace std;

const int xrr[] {1,-1,0,0}, yrr[] {0,0,-1,1};
int n, k, y, x, dir, cnt=1, grid[12][12];
bool ccc = true;
deque<int> board[12][12];
vector<tuple<int, int, int>> loc;
vector<int> stone;

int main() {
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j)
            scanf("%d", &grid[i][j]);
    }
    for (int i = 0; i < k; ++i) {
        scanf("%d %d %d", &y, &x, &dir);
        --y; --x; --dir;
        loc.push_back({ y, x, dir });
        board[y][x].push_back(i);
    }

    function<void(int)> white = [](int a) {
        if (grid[y+yrr[dir]][x+xrr[dir]] == 2) return;

        while (!board[y][x].empty()) {
            stone.push_back(board[y][x].front());
            board[y][x].pop_front();
            if (stone.back() == a) break;
        }

        while (!stone.empty()) {
            board[y+yrr[dir]][x+xrr[dir]].push_front(stone.back());
            loc[stone.back()] = { y+yrr[dir], x+xrr[dir], get<2>(loc[stone.back()]) };
            stone.pop_back();
        }

        if (board[y+yrr[dir]][x+xrr[dir]].size() > 3) ccc = false;
    };

    function<void(int)> red = [](int a) {
        while (!board[y][x].empty()) {
            stone.push_back(board[y][x].front());
            board[y][x].pop_front();
            if (stone.back() == a) break;
        }

        reverse(stone.begin(), stone.end());

        while (!stone.empty()) {
            board[y+yrr[dir]][x+xrr[dir]].push_front(stone.back());
            loc[stone.back()] = { y+yrr[dir], x+xrr[dir], get<2>(loc[stone.back()]) };
            stone.pop_back();
        }

        if (board[y+yrr[dir]][x+xrr[dir]].size() > 3) ccc = false;
    };

    for ( ; cnt < 1002; ++cnt){
        for (int f = 0; f < k; ++f) {
            y = get<0>(loc[f]);
            x = get<1>(loc[f]);
            dir = get<2>(loc[f]);

            if (0<=y+yrr[dir]&&y+yrr[dir]<n && 0<=x+xrr[dir]&&x+xrr[dir]<n) {
                if (grid[y+yrr[dir]][x+xrr[dir]] == 2) {
                    if (dir == 0) dir = 1;
                    else if (dir == 1) dir = 0;
                    else if (dir == 2) dir = 3;
                    else if (dir == 3) dir = 2;

                    loc[f] = { y, x, dir };
                }

                if (0>y+yrr[dir]||y+yrr[dir]>=n || 0>x+xrr[dir]||x+xrr[dir]>=n) continue;

                switch (grid[y+yrr[dir]][x+xrr[dir]]) {
                    case 0:
                        white(f);
                        break;
                    case 1:
                        red(f);
                        break;
                    default:
                        break;
                }
            }
            else {
                if (dir == 0) dir = 1;
                else if (dir == 1) dir = 0;
                else if (dir == 2) dir = 3;
                else if (dir == 3) dir = 2;

                loc[f] = { y, x, dir };

                switch (grid[y+yrr[dir]][x+xrr[dir]]) {
                    case 0:
                        white(f);
                        break;
                    case 1:
                        red(f);
                        break;
                    default:
                        break;
                }
            }

            if (!ccc) break;
        }

        if (cnt > 1000) { cnt = -1; break; }
        if (!ccc) break;
    }

    printf("%d", cnt);

    return 0;
}
