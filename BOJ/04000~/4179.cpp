#include <iostream>
#include <queue>
using namespace std;

const int xrr[] {-1,1,0,0}, yrr[] {0,0,1,-1};
int r, c, x, y, dx, dy, size, ans;
char ch;
bool maze[1000][1000], visited[1000][1000];
queue<pair<int, int>> fire, jihoon;

int main() {
    scanf("%d %d", &r, &c);
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            scanf(" %c", &ch);
            if (ch == '#')
                maze[i][j] = false;
            else if (ch == 'F') {
                fire.push({ i, j });
                maze[i][j] = false;
            }
            else if (ch == 'J') {
                jihoon.push({ i, j });
                maze[i][j] = true;
                visited[i][j] = true;
            }
            else
                maze[i][j] = true;
        }
    }

    while (true) {
        size = fire.size();
        while (size--) {
            y = fire.front().first;
            x = fire.front().second;
            fire.pop();

            for (int i = 0; i < 4; ++i) {
                dy = y + yrr[i];
                dx = x + xrr[i];

                if (0<=dy&&dy<r && 0<=dx&&dx<c && maze[dy][dx]) {
                    maze[dy][dx] = false;
                    fire.push({ dy, dx });
                }
            }
        }

        size = jihoon.size();
        if (size == 0) { ans = 1e9; break; }
        while (size--) {
            y = jihoon.front().first;
            x = jihoon.front().second;
            jihoon.pop();

            if (y == 0 || y == r-1 || x == 0 || x == c-1) {
                ++ans; goto ANS;
            }

            for (int i = 0; i < 4; ++i) {
                dy = y + yrr[i];
                dx = x + xrr[i];

                if (0<=dy&&dy<r && 0<=dx&&dx<c && maze[dy][dx] && !visited[dy][dx]) {
                    visited[dy][dx] = true;
                    jihoon.push({ dy, dx });
                }
            }
        }

        ++ans;
    }

    ANS:
    if (ans == 1e9) printf("IMPOSSIBLE");
    else printf("%d", ans);

    return 0;
}
