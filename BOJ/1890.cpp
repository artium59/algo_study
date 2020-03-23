#include <cstdio>
using namespace std;
using ll = long long;

int n, board[100][100];
ll dp[100][100];

int main() {
    dp[0][0] = 1;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            scanf("%d", &board[i][j]);

            if (dp[i][j] > 0 && board[i][j] > 0) {
                if (j+board[i][j] < n)
                    dp[i][j+board[i][j]] += dp[i][j];

                if (i+board[i][j] < n)
                    dp[i+board[i][j]][j] += dp[i][j];
            }
        }
    }

    printf("%lld", dp[n-1][n-1]);
	return 0;
}
