#include <cstdio>
#include <algorithm>
#include <vector>

inline int max(int a, int b) { return a > b ? a : b; }

int n, t, loc, ans;
std::vector<int> tmp, stk;
std::vector<std::pair<int, int>> order;

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &t);

        loc = lower_bound(tmp.begin(), tmp.end(), t) - tmp.begin();

        if (loc == tmp.size()) tmp.push_back(t);
        else tmp[loc] = t;

        order.push_back({ t, loc });
        ans = max(ans, loc);
    }

    printf("%d\n", ans+1);
    for (int i = n; i > 0; --i) {
        if (ans == order[i-1].second)
            stk.push_back(order[i-1].first), --ans;
    }

    for (int i = stk.size(); i > 0; --i)
        printf("%d ", stk[i-1]);

    return 0;
}
