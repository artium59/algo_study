#include <iostream>
#include <queue>
using namespace std;

const int yrr[] {-2,-2,0,0,2,2}, xrr[] {-1,1,-2,2,-1,1};
int n, cnt, x, y, dx, dy, a, b, board[200][200];
bool visited[200][200];
queue<pair<int, int>> q;

int main(void) {
    scanf("%d", &n);
    scanf("%d %d %d %d", &y, &x, &a, &b);

    q.push({ y, x });
    visited[y][x] = true;
    for (cnt = 1; ; ++cnt) {
        int size = q.size();
        for (int k = 0; k < size; ++k) {
            y = q.front().first;
            x = q.front().second;
            q.pop();

            if (visited[a][b]) break;

            for (int i = 0; i < 6; ++i) {
                dy = y + yrr[i];
                dx = x + xrr[i];

                if (0<=dy&&dy<n && 0<=dx&&dx<n) {
                    if (visited[dy][dx]) continue;
                    visited[dy][dx] = true;
                    q.push({ dy, dx });
                }
            }
        }

        if (visited[a][b] || size == 0) break;
    }

    if (!visited[a][b]) cnt = -1;
    printf("%d", cnt);
    return 0;
}
