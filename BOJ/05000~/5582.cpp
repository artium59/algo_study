#include <iostream>
using namespace std;

int dp[4001][4001], ans, ii, jj;
string a, b;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> a >> b;
    
    ii = a.size(); jj = b.size();
    for (int i = 1; i <= ii; ++i) {
        for (int j = 1; j <= jj; ++j) {
            if (a[i-1] == b[j-1])
                dp[i][j] = dp[i-1][j-1] + 1;
            if (dp[i][j] > ans) ans = dp[i][j];
        }
    }
    
    cout << ans;

    return 0;
}
