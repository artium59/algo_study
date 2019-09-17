#include <iostream>
using namespace std;

int ans, dp[41];
string str;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> str;
    str.insert(0, "0");
    
    dp[0] = 1;
    for (int i = 1; i <= str.size(); i++) {
        if (str[i] != '0') dp[i] += dp[i-1];
        
        if ('0' < str[i-1] && str[i-1] < '3') dp[i] += dp[i-2];
        if (str[i-1] == '3' && str[i] < '5') dp[i] += dp[i-2];
    }
    
    cout << dp[str.size()-1];

    return 0;
}
