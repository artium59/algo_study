#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
using namespace std;

int n, k, m, v, c;
long long ans;
multiset<int> bags;
vector<pair<int, int>> jewels;

int main() {
    scanf("%d %d", &n, &k);
    while (n--) {
        scanf("%d %d", &m, &v);
        jewels.push_back({ m, v });
    }
    while (k--) {
        scanf("%d", &c);
        bags.insert(c);
    }

    sort(jewels.begin(), jewels.end(), [](const auto& a, const auto& b) {
        if (a.second == b.second) return a.first < b.first;
        else return a.second > b.second;
    });

    for (const auto& j : jewels) {
        auto it = bags.lower_bound(j.first);

        if (it == bags.end()) continue;

        ans += j.second;
        bags.erase(it);
    }

    printf("%lld", ans);
    return 0;
}
