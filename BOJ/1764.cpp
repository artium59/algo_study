#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n, m, t;
string str;
vector<string> hear, see, ans;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> str;
        hear.push_back(str);
    }
    for (int i = 0; i < m; i++) {
        cin >> str;
        see.push_back(str);
    }

    sort(hear.begin(), hear.end());
    sort(see.begin(), see.end());
    
    for (const auto& h : hear) {
        t = lower_bound(see.begin(), see.end(), h) - see.begin();
        
        if (see[t] == h) ans.push_back(h);
    }
    
    cout << ans.size() << "\n";
    for (const auto& a : ans) cout << a << "\n";

    return 0;
}
