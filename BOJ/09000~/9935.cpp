#include <iostream>
#include <stack>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int loc;
    string str, bomb, ans;
    stack<char> stk;

    cin >> str >> bomb;

    for (const auto& s : str) {
        string extra;
        loc = bomb.size() - 1;

        if (s == bomb[loc]) {
            extra += s; loc--;

            while (!stk.empty() && stk.top() == bomb[loc]) {
                extra += stk.top();
                loc--; stk.pop();
                if (loc == -1) break;
            }

            if (loc != -1) {
                for (int i = extra.size(); i > 0; i--)
                    stk.push(extra[i-1]);
            }
        }
        else stk.push(s);
    }

    if (stk.size() == 0) cout << "FRULA";
    else {
        while (!stk.empty()) {
            ans += stk.top();
            stk.pop();
        }

        loc = ans.size();
        for (int i = loc; i > 0; i--)
            cout << ans[i-1];
    }

    return 0;
}
