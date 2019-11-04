#include <cstdio>
#include <algorithm>
#include <vector>

int n, s, t, u;
long long ans;
std::vector<int> vec[2];

int main() {
    scanf("%d %d", &n, &s);
    for (int i = 0; i < n/2; ++i) {
        scanf("%d", &t);
        u = vec[0].size();
        for (int j = 0; j < u; ++j) vec[0].push_back(vec[0][j]+t);
        vec[0].push_back(t);
    }
    for (int i = n/2; i < n; ++i) {
        scanf("%d", &t);
        u = vec[1].size();
        for (int j = 0; j < u; ++j) vec[1].push_back(vec[1][j]+t);
        vec[1].push_back(t);
    }
    sort(vec[0].begin(), vec[0].end());
    sort(vec[1].begin(), vec[1].end());

    for (const auto& v : vec[0]) {
        t = lower_bound(vec[1].begin(), vec[1].end(), s-v) - vec[1].begin();
        u = upper_bound(vec[1].begin(), vec[1].end(), s-v) - vec[1].begin();

        if (v == s) ++ans;
        ans += u-t;
    }

    t = lower_bound(vec[1].begin(), vec[1].end(), s) - vec[1].begin();
    u = upper_bound(vec[1].begin(), vec[1].end(), s) - vec[1].begin();

    printf("%lld", ans+u-t);

    return 0;
}
