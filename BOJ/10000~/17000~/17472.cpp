#include <bits/stdc++.h>
using namespace std;

const int MAX = 1e4;
const int yrr[4] {-1,1,0,0}, xrr[4] {0,0,-1,1};
int tc, n, m, cnt, cur, other, ans, island[10][10], dist[6][6], answer[6];
bool visited[6];
vector<int> vec(1, 0);

int main() {
    function<void(int, int, int)> coloring = [&](int y, int x, int color) {
        int dy, dx;

        for (int i = 0; i < 4; i++) {
            dy = y + yrr[i];
            dx = x + xrr[i];

            if (0<=dy&&dy<n && 0<=dx&&dx<m && island[dy][dx] == -1) {
                island[dy][dx] = color;
                coloring(dy, dx, color);
            }
        }
    };

    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &island[i][j]);
            island[i][j] -= 2;
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (island[i][j] == -1) {
                island[i][j] = cnt;
                coloring(i, j, cnt++);
            }
        }
    }

    for (int i = 0; i < cnt; i++) {
        for (int j = 0; j < cnt; j++)
            dist[i][j] = MAX;
    }

    for (int a = 0; a < n; a++) {
        for (int b = 0; b < m; b++) {
            if (island[a][b] == -2) continue;

            cur = island[a][b];
            // left
            for (int j = 1; b-j >= 0; j++) {
                other = island[a][b-j];
                if (other >= 0) {
                    if (j > 2 && other != cur) {
                        dist[cur][other] = min(dist[cur][other], j-1);
                        dist[other][cur] = dist[cur][other];
                    }
                    break;
                }
            }

            // right
            for (int j = 1; b+j < m; j++) {
                other = island[a][b+j];
                if (other >= 0) {
                    if (j > 2 && other != cur) {
                        dist[cur][other] = min(dist[cur][other], j-1);
                        dist[other][cur] = dist[cur][other];
                    }
                    break;
                }
            }

            // up
            for (int i = 1; a-i >= 0; i++) {
                other = island[a-i][b];
                if (other >= 0) {
                    if (i > 2 && other != cur) {
                        dist[cur][other] = min(dist[cur][other], i-1);
                        dist[other][cur] = dist[cur][other];
                    }
                    break;
                }
            }

            //down
            for (int i = 1; a+i < n; i++) {
                other = island[a+i][b];
                if (other >= 0) {
                    if (i > 2 && other != cur) {
                        dist[cur][other] = min(dist[cur][other], i-1);
                        dist[other][cur] = dist[cur][other];
                    }
                    break;
                }
            }
        }
    }

    for (int i = 0; i < cnt; i++)
        answer[i] = MAX;

    for (int a = 0; a < cnt-1; a++) {
        visited[vec.back()] = true;

        int small = MAX, small_idx = 0;
        int size = vec.size();
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < cnt; j++) {
                if (visited[j]) continue;

                answer[j] = min(answer[j], dist[vec[i]][j]);
                if (small > answer[j]) {
                    small = answer[j];
                    small_idx = j;
                }
            }
        }
        vec.push_back(small_idx);
    }

    for (int i = 1; i < cnt; i++)
        ans += answer[i];

    if (ans >= MAX) ans = -1;
    printf("%d", ans);

    return 0;
}
