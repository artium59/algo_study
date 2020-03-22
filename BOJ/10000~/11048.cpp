#include <cstdio>
using namespace std;

int n, m, dp[1001][1001];

inline int max(int a, int b) { return a > b ? a : b; }

int main() {
    scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			scanf("%d", &dp[i][j]);
			dp[i][j] += max(dp[i-1][j], dp[i][j-1]);
		}
	}

	printf("%d", dp[n][m]);
	return 0;
}
