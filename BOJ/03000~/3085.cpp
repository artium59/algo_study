#include <iostream>
#include <functional>
using namespace std;

int n, ans = 1;
char tmp, board[50][50];

int main() {
    freopen("input.txt", "r", stdin);

    function<void(int, int)> row = [](int i, int j) {
        int cnt = 1;

        for (int k = j-1; k >= 0; --k) {
            if (board[i][j] != board[i][k])
                break;
            ++cnt;
        }
        for (int k = j+1; k < n; ++k) {
            if (board[i][j] != board[i][k])
                break;
            ++cnt;
        }

        ans = max(ans, cnt);
    };

    function<void(int, int)> col = [](int i, int j) {
        int cnt = 1;

        for (int k = i-1; k >= 0; --k) {
            if (board[i][j] != board[k][j])
                break;
            ++cnt;
        }
        for (int k = i+1; k < n; ++k) {
            if (board[i][j] != board[k][j])
                break;
            ++cnt;
        }

        ans = max(ans, cnt);
    };

    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j)
            scanf(" %c", &board[i][j]);
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i < n-1 && board[i][j] != board[i+1][j]) {
                // up-down
                tmp = board[i][j];
                board[i][j] = board[i+1][j];
                board[i+1][j] = tmp;

                for (int a = 0; a < n; ++a) {
                    for (int b = 0; b < n; ++b) {
                        row(a, b);
                        col(a, b);
                    }
                }

                tmp = board[i][j];
                board[i][j] = board[i+1][j];
                board[i+1][j] = tmp;
            }

            if (j < n-1 && board[i][j] != board[i][j+1]) {
                // left right
                tmp = board[i][j];
                board[i][j] = board[i][j+1];
                board[i][j+1] = tmp;

                for (int a = 0; a < n; ++a) {
                    for (int b = 0; b < n; ++b) {
                        row(a, b);
                        col(a, b);
                    }
                }

                tmp = board[i][j];
                board[i][j] = board[i][j+1];
                board[i][j+1] = tmp;
            }
        }
    }

    printf("%d", ans);
    return 0;
}
