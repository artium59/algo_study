#include <bits/stdc++.h>

int main() {
    int n, l, t;
    std::vector<int> h;
    
    scanf("%d %d", &n, &l);
    
    for (int i = 0; i < n; i++) {
        scanf("%d", &t);
        h.push_back(t);
    }
    
    sort(h.begin(), h.end());
    
    for (int j = 0; j < n; j++) {
        if (l >= h[j])
            l++;
        else
            break;
    }
    
    printf("%d", l);
    
    return 0;
}