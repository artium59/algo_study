#include <bits/stdc++.h>

int main() {
    long long n, m, t, u, start = 0, end = 0;
    std::vector<long long> trees;
    scanf("%lld %lld", &n, &m);
    
    for (int h = 0; h < n; h++) {
        scanf("%lld", &t);
        trees.push_back(t);
        if (t > end) end = t;
    }
    
    while (start + 1 < end) {
        u = m;
        t = (start+end) / 2;
        
        for (int i = 0; i < n; i++) {
            if (trees[i] - t > 0)
                u -= (trees[i] - t);
        }
        
        if (u > 0) end = t;
        else start = t;
    }
    
    printf("%lld", start);
    
    return 0;
}