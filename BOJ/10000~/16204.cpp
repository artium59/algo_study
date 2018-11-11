#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m, k, ans;
    
    scanf("%d %d %d", &n, &m, &k);
    
    if (m > k)
        ans = k + (n - m);
    else if (m == k)
        ans = n;
    else
        ans = m + (n - k);
    
    printf("%d", ans);
    
    return 0;
}