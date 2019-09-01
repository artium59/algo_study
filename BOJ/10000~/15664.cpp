#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
using namespace std;

int n, m, e, arr[8];
vector<string> ans;
set<string> check;

void Find(string cur, int start, int cnt) {
    if (cnt == m) {
        ans.push_back(cur); return;
    }
    
    for (int i = start+1; i < n; i++)
        Find(cur+" "+to_string(arr[i]), i, cnt+1);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> arr[i];

    sort(arr, arr+n);
    for (int i = 0; i < n; i++) Find(to_string(arr[i]), i, 1);
    
    for (int i = 0; i < ans.size(); i++) {
        if (check.find(ans[i]) != check.end()) continue;
        cout << ans[i] << "\n";
        check.insert(ans[i]);
    }

    return 0;
}
