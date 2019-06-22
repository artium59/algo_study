#include <iostream>
#include <queue>
using namespace std;

int n, l, t;
deque<pair<int, int>> dq;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> l;
    for (int i = 0; i < n; i++) {
        cin >> t;

        while (!dq.empty() && i-dq.back().second < l && dq.back().first > t) {
            dq.pop_back();
        }

        dq.push_back(make_pair(t, i));

        if (i - dq.front().second >= l) dq.pop_front();

        printf("%d ", dq.front().first);
    }

    return 0;
}
