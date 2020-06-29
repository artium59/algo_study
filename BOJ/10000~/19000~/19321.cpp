#include <iostream>
#include <algorithm>

int n, ans[100000];
std::pair<int, int> p[100000];

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &p[i].first);
        p[i].second = i;
    }

    std::sort(p, p+n, [](const auto& a, const auto& b) {
        if (a.first == b.first) return a.second > b.second;
        else return a.first < b.first;
    });

    for (int i = 0; i < n; ++i)
        ans[p[i].second] = i+1;

    for (int i = 0; i < n; ++i)
        printf("%d ", ans[i]);

    return 0;
}
