#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int m, n, l, x, y, z;
vector<int> guns;
vector<pair<int, int>> animals;

inline int dist(int loc, pair<int, int> p) {
    return p.second + abs(p.first - guns[loc]);
}

int main() {
    scanf("%d %d %d", &m, &n, &l);
    for (int i = 0; i < m; ++i) {
        scanf("%d", &x);
        guns.push_back(x);
    }
    for (int i = 0; i < n; ++i) {
        scanf("%d %d", &x, &y);
        if (y <= l) animals.push_back({ x, y });
    }
    sort(guns.begin(), guns.end());

    x = y = 0;
    for (const auto& a : animals) {
        x = lower_bound(guns.begin(), guns.end(), a.first-(l-a.second)) - guns.begin();
        y = lower_bound(guns.begin(), guns.end(), a.first+(l-a.second)) - guns.begin();

        if (dist(x, a) <= l || dist(y, a) <= l) ++z;
    }
    printf("%d", z);

    return 0;
}
