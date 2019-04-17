#include <iostream>
#include <stack>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, ans = 0;
    string str;

    cin >> n;
    while (n--) {
        stack<char> stk;

        cin >> str;

        for (const auto& s : str) {
            if (stk.empty()) stk.push(s);
            else {
                if (stk.top() == s) stk.pop();
                else stk.push(s);
            }
        }

        if (stk.empty()) ans++;
    }

    cout << ans;

    return 0;
}
