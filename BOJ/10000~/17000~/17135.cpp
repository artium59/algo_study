#include <iostream>
#include <algorithm>
#include <queue>
#include <set>

inline int max(int a, int b) { return a > b ? a : b; }

int n, m, d, x, y, t, ans, line, archer[3], enemy[15][15], tmp_enemy[15][15];
bool ar[15];
std::set<std::pair<int, int>> myset;

void search(int land, int loc) {
    std::queue<std::pair<int, int>> q;

    if (d == 1) return;

    if (0 < loc && tmp_enemy[land][loc-1] == 1) {
        myset.insert({ land, loc-1 });
        return;
    }
    if (0 < land && tmp_enemy[land-1][loc] == 1) {
        myset.insert({ land-1, loc });
        return;
    }
    if (loc < m-1 && tmp_enemy[land][loc+1] == 1) {
        myset.insert({ land, loc+1 });
        return;
    }

    if (0 < loc) q.push({ land, loc-1 });
    if (0 < land) q.push({ land-1, loc });
    if (loc < m-1) q.push({ land, loc+1 });

    while (!q.empty()) {
        y = q.front().first;
        x = q.front().second;
        q.pop();

        if (abs(x-loc)+land-y >= d-1) return;

        if (y == land) {
            if (x < loc) {
                if (x > 0 && tmp_enemy[y][x-1] == 1) {
                    myset.insert({ y, x-1 });
                    return;
                }
                if (y > 0 && tmp_enemy[y-1][x] == 1) {
                    myset.insert({ y-1, x });
                    return;
                }

                if (x > 0) q.push({ y, x-1 });
                if (y > 0) q.push({ y-1, x });
            }
            else {
                if (y > 0 && tmp_enemy[y-1][x] == 1) {
                    myset.insert({ y-1, x });
                    return;
                }
                if (x < m-1 && tmp_enemy[y][x+1] == 1) {
                    myset.insert({ y, x+1 });
                    return;
                }

                if (y > 0) q.push({ y-1, x });
                if (x < m-1) q.push({ y, x+1 });
            }
        }
        else {
            if (y == 0) continue;

            if (tmp_enemy[y-1][x] == 1) {
                myset.insert({ y-1, x });
                return;
            }

            q.push({ y-1, x });
        }
    }
}

int main() {
    scanf("%d %d %d", &n, &m, &d);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j)
            scanf("%d", &enemy[i][j]);
    }

    std::fill(ar, ar+3, true);

    do {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j)
                tmp_enemy[i][j] = enemy[i][j];
        }

        line = t = 0;
        for (int i = 0; i < m; i++) {
            if (ar[i]) archer[line] = i, line++;
            if (line == 3) break;
        }

        line = n;
        while (line--) {
            for (const auto& a : archer) {
                if (tmp_enemy[line][a] == 1) {
                    myset.insert({ line, a });
                    continue;
                }

                search(line, a);
            }

            t += myset.size();
            for (const auto& ms : myset)
                tmp_enemy[ms.first][ms.second] = 0;
            myset.clear();
        }

        ans = max(ans, t);
    } while (std::prev_permutation(ar, ar+m));

    printf("%d", ans);

    return 0;
}
