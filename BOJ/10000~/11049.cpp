#include <iostream>

inline int min(int a, int b) { return a < b ? a : b; }

int n, r, c, dp[500][500];
std::pair<int, int> p[500];

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &r, &c);
        p[i].first = r; p[i].second = c;
    }

    for (int s = n-2; s >= 0; s--) {
        for (int e = s+1; e < n; e++) {
            dp[s][e] = min(dp[s+1][e] + p[s].first*p[s].second*p[e].second,
                                dp[s][e-1] + p[s].first*p[e].first*p[e].second);

            for (int m = s+1; m < e-1; m++)
                dp[s][e] = min(dp[s][e], dp[s][m]+dp[m+1][e]+p[s].first*p[m].second*p[e].second);
        }
    }

    printf("%d", dp[0][n-1]);

    return 0;
}
