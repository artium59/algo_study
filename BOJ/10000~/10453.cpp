#include <iostream>
#include <stack>
using namespace std;

inline int abs(int a) { return a < 0 ? -a : a; }

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t, ans;
    string x, y;
    stack<int> stk[2];

    cin >> t;
    while (t--) {
        ans = 0;

        cin >> x >> y;
        for (int i = 0; i < x.size(); i++) {
            if (x[i] != y[i]) stk[x[i]-'a'].push(i);
        }

        while (!stk[0].empty() && !stk[1].empty()) {
            ans += abs(stk[0].top() - stk[1].top());
            stk[0].pop(); stk[1].pop();
        }

        printf("%d\n", ans);
    }

    return 0;
}
