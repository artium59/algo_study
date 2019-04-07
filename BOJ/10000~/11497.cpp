#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

inline int max(int a, int b) { return a > b ? a : b; }

int main() {
    int t, n, k, ans;
    bool turn;

    scanf("%d", &t);
    while (t--) {
        ans = 0; turn = false;
        deque<int> dq;
        vector<int> logs;

        scanf("%d", &n);
        while (n--) {
            scanf("%d", &k);
            logs.push_back(k);
        }

        sort(logs.begin(), logs.end(), greater<int>());

        for (const auto& l : logs) {
            if (turn) {
                if (!dq.empty()) ans = max(ans, dq.back()-l);
                dq.push_back(l);
                turn = !turn;
            }
            else {
                if (!dq.empty()) ans = max(ans, dq.front()-l);
                dq.push_front(l);
                turn = !turn;
            }
        }

        printf("%d\n", ans);
    }

    return 0;
}
