#include <bits/stdc++.h>

int main() {
    int n, t, ans = 0;
    std::vector<int> rope;
    scanf("%d", &n);
    
    for (int a = 0; a < n; a++) {
        scanf("%d", &t);
        rope.push_back(t);
    }
    
    sort(rope.begin(), rope.end());
    
    for (int b = 0; b < n; b++)
        ans = (rope[b] * (n-b)) > ans ? rope[b] * (n-b) : ans;
    
    printf("%d", ans);
    
    return 0;
}