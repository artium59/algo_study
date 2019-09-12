#include <cstdio>

inline int min(int a, int b) { return a < b ? a : b; }

int r, c, extra, ans = 0, dp[752][752][2];
char dia[752][752];

int main() {
    scanf("%d %d", &r, &c);
    for (int i = 1; i <= r; i++) {
        for (int j = 1; j <= c; j++) {
            scanf(" %c", &dia[i][j]);
            
            if (dia[i][j] == '0') {
                dp[i][j][0] = dp[i][j][1] = 0;
                continue;
            }
            
            dp[i][j][0] = dp[i-1][j-1][0] + dia[i][j] - '0';
            dp[i][j][1] = dp[i-1][j+1][1] + dia[i][j] - '0';
            
            extra = min(dp[i][j][0], dp[i][j][1]);
            
            for ( ; extra > ans; extra--) {
                if (dp[i-extra+1][j-extra+1][1] >= extra &&
                        dp[i-extra+1][j+extra-1][0] >= extra)
                    ans = extra;
            }
        }
    }

    printf("%d", ans);

    return 0;
}
