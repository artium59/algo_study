#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

const int yrr[] {-1,1,-1,0,0,0,1,1,1}, xrr[] {-1,0,1,-1,0,1,-1,0,1};
int y, x, t, dy, dx, s;
char ch;
bool check, board[8][8], visited[8][8];
queue<pair<int, int>> q;

int main(void) {
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            scanf(" %c", &ch);
            board[i][j] = ch == '.';
        }
    }

    q.push({ 7, 0 });
    while (!q.empty() && !check) {
        s = q.size();
        memset(visited, false, sizeof(visited));

        for (int k = 0; k < s; ++k) {
            y = q.front().first;
            x = q.front().second;
            q.pop();

            if (!board[y][x]) continue;
            if (y == 0 && x == 7) {
                check = true; break;
            }

            for (int i = 0; i < 9; ++i) {
                dy = y + yrr[i];
                dx = x + xrr[i];

                if (0<=dy&&dy<8 && 0<=dx&&dx<8) {
                    if (board[dy][dx] && !visited[dy][dx]) {
                        if (0 < dy && !board[dy-1][dx]) continue;

                        visited[dy][dx] = true;
                        q.push({ dy, dx });
                    }
                }
            }
        }

        for (int i = 7; i >= 0; --i) {
            for (int j = 0; j < 8; ++j) {
                if (i == 0) board[i][j] = true;
                else board[i][j] = board[i-1][j];
            }
        }
    }

    printf("%d", check);
    return 0;
}
