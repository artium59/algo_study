#include <iostream>
#include <vector>

int max(int a, int b) {
    return a > b ? a : b;
}

int main() {
    int n, t;
    std::vector<int> stairs, ans;
    
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &t);
        stairs.push_back(t);
        ans.push_back(0);
    }
    
    ans[0] = stairs[0];
    if (n > 0) ans[1] = stairs[0] + stairs[1];
    if (n > 1) ans[2] = max(stairs[0], stairs[1]) + stairs[2];
    
    for (int i = 3; i < n; i++)
        ans[i] = stairs[i] + max(ans[i-3] + stairs[i-1], ans[i-2]);
    
    printf("%d", ans[n-1]);
    
    return 0;
}
