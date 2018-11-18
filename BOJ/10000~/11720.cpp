#include <bits/stdc++.h>

int main() {
    int n, ans = 0;
    std::string s;
    std::cin >> n >> s;
    
    for (int i = 0; i < n; i++)
        ans += s[i];
    
    printf("%d", ans - '0'*n);
    
    return 0;
}