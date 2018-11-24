#include <bits/stdc++.h>

int main() {
    int t;
    scanf("%d", &t);
    
    for (int h = 0; h < t; h++) {
        int m, n, x, y, i = 0, j = 0, lcm, ans;
        scanf("%d %d %d %d", &m, &n, &x, &y);
        
        lcm = (m*n)/(std::__gcd(m, n));
        
        while (1) {
            if (m*i + x > n*j + y)
                j++;
            else if (m*i + x < n*j + y)
                i++;
            else {
                ans = m*i + x;
                break;
            }
            
            if (m*i + x > lcm || n*j + y > lcm) {
                ans = -1;
                break;
            }
        }
        
        printf("%d\n", ans);
    }
    
    return 0;
}