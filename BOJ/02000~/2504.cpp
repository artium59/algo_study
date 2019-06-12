#include <iostream>
#include <stack>
using namespace std;

const int MAX = 15000000;
int n, ans = 0;
bool swch = true;
string str;
stack<int> stk;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> str;
    for (const auto& ch : str) {
        if (ch == '[' || ch == '(') {
            stk.push(MAX+ch); continue;
        }

        if (stk.empty()) break;

        n = stk.top(); stk.pop();
        if (n < 0) {
            swch = false; break;
        }

        if (ch == ')') {
            if (n == MAX+'(') stk.push(2);
            else if (n == MAX+'[') {
                swch = false; break;
            }
            else {
                while (!stk.empty() && stk.top() < MAX) {
                    n += stk.top(); stk.pop();
                }

                if (stk.empty() || stk.top() != MAX+'(') {
                    swch = false; break;
                }

                stk.pop(); stk.push(2*n);
            }
        }
        else if (ch == ']') {
            if (n == MAX+'[') stk.push(3);
                else if (n == MAX+'(') {
                    swch = false; break;
                }
            else {
                while (!stk.empty() && stk.top() < MAX) {
                    n += stk.top(); stk.pop();
                }

                if (stk.empty() || stk.top() != MAX+'[') {
                    swch = false; break;
                }

                stk.pop(); stk.push(3*n);
            }
        }
        else break;
    }

    while (!stk.empty()) {
        if (stk.top() > MAX) { ans = 0; break; }
        ans += stk.top(); stk.pop();
    }
    if (!swch) ans = 0;
    cout << max(0, ans);

    return 0;
}
