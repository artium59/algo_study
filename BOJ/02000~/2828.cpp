#include <bits/stdc++.h>

int main() {
    int n, m, j, t, l = 1, ans = 0;
    bool isLeft = false;
    std::vector<int> apples;
    scanf("%d %d %d", &n, &m, &j);
    
    for (int a = 0; a < j; a++) {
        scanf("%d", &t);
        apples.push_back(t);
    }
    
    for (int b = 0; b < j; b++) {
        isLeft = ((l + m - 1) > apples[b]) ? true : false;
        
        if (l > apples[b] || apples[b] > l + m - 1) {
            if (isLeft) {
                ans += l - apples[b];
                l = apples[b];
            }
            else {
                ans += apples[b] + 1 - m - l;
                l = apples[b] + 1 - m;
            }
        }
    }
    
    printf("%d", ans);
    
    return 0;
}