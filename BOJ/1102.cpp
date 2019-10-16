#include <cstdio>
#include <cstring>

inline int min(int a, int b) { return a < b ? a : b; }
inline int count(int a) { return __builtin_popcount(a); }

const int MAX = 1e9;
int n, p, plant[16][16], dp[1<<16], use, ans;
char ch;

int fix(int t) {
    if (count(t) >= p) return 0;

    int& ret = dp[t];
    if (ret != -1) return ret;
    ret = MAX;

    for (int i = 0; i < n; i++) {
        if (!(1<<i & t)) continue;

        for (int j = 0; j < n; j++) {
            if (1<<j & t) continue;

            ret = min(ret, fix(t | 1<<j)+plant[i][j]);
        }
    }

    return ret;
}

int main() {
    memset(dp, -1, sizeof(dp));

    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            scanf("%d", &plant[i][j]);
    }
    for (int i = 0; i < n; i++) {
        scanf(" %c", &ch);
        if (ch == 'Y') use |= 1 << i;
    }
    scanf("%d", &p);

    if (count(use) >= p) ans = 0;
    else if (p > n || use == 0) ans = -1;
    else ans = fix(use);

    printf("%d", ans);

    return 0;
}
