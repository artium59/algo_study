#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

int n, m, e, arr[8];
set<string> check;

void Find(string cur, int cnt, int visited) {
    if (cnt == m) {
        if (check.find(cur) == check.end()) {
            cout << cur << "\n";
            check.insert(cur);
        }
        
        return;
    }
    
    for (int i = 0; i < n; i++) {
        if (visited & 1<<i) continue;
        Find(cur+" "+to_string(arr[i]), cnt+1, visited|1<<i);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> arr[i];

    sort(arr, arr+n);
    for (int i = 0; i < n; i++) Find(to_string(arr[i]), 1, 1<<i);

    return 0;
}
