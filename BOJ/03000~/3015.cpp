#include <iostream>
#include <stack>
using namespace std;

int n;
long long ans;
pair<int, int> p;
stack<pair<int, int>> stk;

int main(void) {
    scanf("%d", &n);
    while (n--) {
        scanf("%d", &p.first);
        p.second = 1;

        while (!stk.empty()) {
            if (stk.top().first > p.first) {
                ++ans;
                break;
            }
            else if (stk.top().first == p.first)
                p.second += stk.top().second;
            ans += stk.top().second;
            stk.pop();
        }
        stk.push(p);
    }

    printf("%lld", ans);
    return 0;
}
