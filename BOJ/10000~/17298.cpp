#include <stdio.h>
#include <stack>

const int MAX = 1000000;
int n, t, ans[MAX];
std::stack<std::pair<int, int>> stk;

void func(int cur) {
    while (!stk.empty() && stk.top().first < cur) {
        ans[stk.top().second] = cur;
        stk.pop();
    }
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &t);
        
        func(t);
        stk.push(std::make_pair(t, i));
    }

    for (int i = 0; i < n; i++) {
        if (ans[i] == 0) printf("-1 ");
        else printf("%d ", ans[i]);
    }

    return 0;
}
