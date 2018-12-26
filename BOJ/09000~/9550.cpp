#include <bits/stdc++.h>

int main() {
    int t;
    scanf("%d", &t);
    
    for (int h = 0; h < t; h++) {
        int n, k, c, ans = 0;
        std::vector<int> candy;
        scanf("%d %d", &n, &k);
        
        for (int i = 0; i < n; i++) {
            scanf("%d", &c);
            candy.push_back(c);
        }
        
        sort(candy.begin(), candy.end(), std::greater<int>());
        
        for (int i = 0; i < n; i++) {
            if (candy[i] / k > 0) {
                ans += candy[i] / k;
            }
            else break;
        }
        
        printf("%d\n", ans);
    }
    
    return 0;
}