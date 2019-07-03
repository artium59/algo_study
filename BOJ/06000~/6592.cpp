#include <iostream>
#include <vector>
using namespace std;

int i, j, dp[101][101];
string str;
vector<string> a, b, ans;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    while (!cin.eof()) {
        while (true) {
            cin >> str;
            if (str == "#") break;
            a.push_back(str);
        }
        
        while (true) {
            cin >> str;
            if (str == "#") break;
            b.push_back(str);
        }
        
        for (i = 1; i <= a.size(); i++) {
            for (j = 1; j <= b.size(); j++) {
                dp[i][j] = (a[i-1] == b[j-1]) ? dp[i-1][j-1] + 1 : std::max(dp[i-1][j], dp[i][j-1]);
            }
        }
        
        j = a.size(); i = b.size();
        while (i > 0 && j > 0) {
            if (a[j-1] == b[i-1]) {
                ans.push_back(a[j-1]);
                j--; i--;
            }
            else
                dp[j-1][i] > dp[j][i-1] ? j-- : i--;
        }
        
        while (!ans.empty()) {
            cout << ans.back();
            ans.pop_back();
            
            if (!ans.empty()) cout << " ";
            else cout << "\n";
        }
        
        a.clear(); b.clear();
    }

    return 0;
}
