#include <iostream>
using namespace std;

int n, a, b, ans;
bool board[102][102];

int main() {
    scanf("%d", &n);
    while (n--) {
        scanf("%d %d", &a, &b);
        for (int i = 0; i < 10; ++i) {
            for (int j = 0; j < 10; ++j)
                board[a+i][b+j] = true;
        }
    }

    for (int i = 1; i <= 100; ++i) {
        for (int j = 1; j <= 100; ++j) {
            if (!board[i][j]) continue;

            if (!board[i+1][j]) ++ans;
            if (!board[i-1][j]) ++ans;
            if (!board[i][j+1]) ++ans;
            if (!board[i][j-1]) ++ans;
        }
    }

    printf("%d", ans);
    return 0;
}
