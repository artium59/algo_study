#include <cstdio>
#include <stack>

int main() {
    int k, t;
    std::stack<int> stk;
    
    scanf("%d", &k);
    while (k--) {
        scanf("%d", &t);
        if (t != 0) stk.push(t);
        else stk.pop();
    }

    t = 0;
    while (!stk.empty()) {
        t += stk.top(); stk.pop();
    }
    
    printf("%d", t);

    return 0;
}
