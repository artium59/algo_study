#include <cstdio>
#include <stack>

int n, h;
long long ans;
std::stack<std::pair<int, int>> stk;

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &h);

        while (!stk.empty()) {
            ans += i - stk.top().second + 1;

            if (stk.top().first >= h)
                break;

            stk.pop();
        }
        stk.push({h, i});
    }

    printf("%lld", ans);
    return 0;
}
