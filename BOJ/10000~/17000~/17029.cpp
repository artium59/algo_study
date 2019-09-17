#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n, k, ans=0;
string animal, feature;
vector<string> vec[100];

int find_same(int a, int b) {
    int ret=0, x=0, y=0;
    
    while (x < vec[a].size() && y < vec[b].size()) {
        if (vec[a][x] == vec[b][y]) {
            ret++; x++; y++;
        }
        else if (vec[a][x] < vec[b][y]) x++;
        else y++;
    }
    
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> animal >> k;
        while (k--) {
            cin >> feature;
            vec[i].push_back(feature);
        }
        
        sort(vec[i].begin(), vec[i].end());
    }
    
    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++)
            ans = max(ans, find_same(i, j));
    }
    
    cout << ans+1;

    return 0;
}
