#include <bits/stdc++.h>

int main() {
    std::string a, b;
    std::cin >> a >> b;
    int dp[a.size() + 1][b.size() + 1];
    
    for (int h = 0; h < a.size()+1; h++)
        dp[h][0] = 0;
    
    for (int h = 0; h < b.size()+1; h++)
        dp[0][h] = 0;
    
    
    for (int i = 1; i < a.size()+1; i++) {
        for (int j = 1; j < b.size()+1; j++)
                dp[i][j] = (a[i-1] == b[j-1]) ? dp[i-1][j-1] + 1 : std::max(dp[i-1][j], dp[i][j-1]);
    }
    
    printf("%d", dp[a.size()][b.size()]);
    
    return 0;
}