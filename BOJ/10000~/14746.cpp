#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

inline int abs(int a) { return a < 0 ? -a : a; }

int n, m, x, y1, y2, dist = 987654321, ans = 0, loc;
vector<int> p, q;

int main() {
    scanf("%d %d %d %d", &n, &m, &y1, &y2);
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        p.push_back(x);
    }
    for (int i = 0; i < m; i++) {
        scanf("%d", &x);
        q.push_back(x);
    }

    sort(p.begin(), p.end());
    sort(q.begin(), q.end());

    for_each(p.begin(), p.end(), [](const auto& px) {
        loc = lower_bound(q.begin(), q.end(), px) - q.begin();

        if (-1 < loc && loc < m) {
            if (dist > abs(px-q[loc])) {
                dist = abs(px-q[loc]); ans = 1;
            }
            else if (dist == abs(px-q[loc])) ans++;
        }

        if (0 < loc && loc <= m) {
            if (dist > abs(px-q[loc-1])) {
                dist = abs(px-q[loc-1]); ans = 1;
            }
            else if (dist == abs(px-q[loc-1])) ans++;
        }

        if (-1 <= loc && loc < m-1) {
            if (dist > abs(px-q[loc+1])) {
                dist = abs(px-q[loc+1]); ans = 1;
            }
            else if (dist == abs(px-q[loc+1])) ans++;
        }
    });

    printf("%d %d", dist+abs(y1-y2), ans);

    return 0;
}
