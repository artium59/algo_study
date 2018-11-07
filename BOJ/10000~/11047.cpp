#include <bits/stdc++.h>

int main() {
    int n, k, t, ans = 0;
    std::vector<int> coins;
    
    scanf("%d %d", &n, &k);
    
    for (int a = 0; a < n; a++) {
        scanf("%d", &t);
        coins.push_back(t);
    }
    
    for (int b = n-1; b > -1; b--) {
        if (k >= coins[b]) {
            ans += k / coins[b];
            k %= coins[b];
        }
    }
    
    printf("%d", ans);
    
    return 0;
}