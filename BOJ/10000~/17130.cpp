#include <iostream>

inline int max(int a, int b) { return a > b ? a : b; }

const int LIMIT = 1000;
int ans = -1, c, n, m, x, y, nx, ny, dp[LIMIT][LIMIT];
char island[LIMIT][LIMIT];

void Init() {
    for (int i = 0; i < LIMIT; i++) {
        for (int j = 0; j < LIMIT; j++)
            dp[i][j] = -1;
    }
}

int main(void) {
    Init();

    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf(" %c", &island[i][j]);
            if (island[i][j] == 'R') { y = i; x = j; }
        }
    }

    dp[y][x] = 0;
    for (int j = x+1; j < m; j++) {
        for (int i = 0; i < n; i++) {
            nx = j-1; c = (island[i][j] == 'C');

            if (nx < 0) continue;
            if (island[i][j] == '#') continue;

            ny = i;
            if (dp[ny][nx] > -1)
                dp[i][j] = dp[ny][nx] + c;

            ny = i-1;
            if (ny > -1 && dp[ny][nx] > -1)
                dp[i][j] = max(dp[i][j], dp[ny][nx] + c);

            ny = i+1;
            if (ny < n && dp[ny][nx] > -1)
                dp[i][j] = max(dp[i][j], dp[ny][nx] + c);

            if (island[i][j] == 'O') ans = max(ans, dp[i][j]);
        }
    }

    printf("%d", ans);

    return 0;
}
