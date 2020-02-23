#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n, a, b, ans;
vector<pair<int, int>> vec;

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d %d", &a, &b);
        vec.push_back({ a, b });
    }
    sort(vec.begin(), vec.end());

    a = vec[0].first; b = vec[0].second;
    for (const auto& v : vec) {
        if (a <= v.first && v.first <= b) {
            if (b <= v.second) b = v.second;
        }
        else if (a <= v.second && v.second <= b) {
            if (v.first <= a) a = v.first;
        }
        else {
            ans += b-a;
            a = v.first; b = v.second;
        }
    }

    printf("%d", ans+b-a);

    return 0;
}
