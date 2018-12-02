#include <bits/stdc++.h>

int main() {
    int n, i, t, sum = 0;
    std::vector<int> a, b;
    scanf("%d", &n);
    
    for (i = 0; i < n; i++) {
        scanf("%d", &t);
        a.push_back(t);
    }
    
    for (i = 0; i < n; i++) {
        scanf("%d", &t);
        b.push_back(t);
    }
    
    sort(a.begin(), a.end());
    sort(b.begin(), b.end(), std::greater<int>());
    
    for (i = 0; i < n; i++)
        sum += a[i] * b[i];
    
    printf("%d", sum);
    
    return 0;
}