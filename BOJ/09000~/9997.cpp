#include <iostream>
#include <vector>

using namespace std;

const int all = (1 << 26) - 1;

int n, c, t, ans = 0;
string str;
vector<int> arr;

void Search(int cur, int visited) {
    if (cur + 1 == n) {
        if (visited == all) ans++;
        return;
    }
    else {
        Search(cur+1, visited | arr[cur+1]);
        Search(cur+1, visited);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> str;
        c = 0;
        
        for (const auto& s : str)
            c |= 1 << (s - 'a');
        
        arr.push_back(c);
    }
    
    Search(-1, 0);
    
    cout << ans;
    
    return 0;
}
