#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

int n, m, e, arr[7];
set<string> check;

void Find(string cur, int cnt) {
    if (cnt == m) {
        if (check.find(cur) == check.end()) {
            cout << cur << "\n";
            check.insert(cur);
        }
        
        return;
    }
    
    for (int i = 0; i < n; i++)
        Find(cur+" "+to_string(arr[i]), cnt+1);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> arr[i];

    sort(arr, arr+n);
    for (int i = 0; i < n; i++) Find(to_string(arr[i]), 1);

    return 0;
}
