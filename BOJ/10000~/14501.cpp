#include <iostream>
#include <vector>
using namespace std;

int n, t, p, ans = 0, dp[15];
vector<pair<int, int>> vec;

inline int max(int a, int b) { return a > b ? a : b; }

int Solve(int cur) {
    if (cur >= n) return 0;

    int& ret = dp[cur];
    if (ret != 0) return ret;

    for (int i = cur+vec[cur].first; i <= n; i++)
        ret = max(ret, vec[cur].second + Solve(i));

    return ret;
}

int main() {
    for (int i = 0; i < 15; i++)
        dp[i] = 0;

    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &t, &p);
        vec.push_back(make_pair(t, p));
    }

    for (int i = 0; i < n; i++)
        ans = max(ans, Solve(i));

    printf("%d", ans);

    return 0;
}
