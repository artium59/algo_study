#include <iostream>
#include <algorithm>
using namespace std;

int n;
string s, str[20000];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n;
    for (int i = 0; i < n; i++) cin >> str[i];
    
    sort(str, str+n, [](const auto& a, const auto& b) {
        if (a.size() != b.size()) return a.size() < b.size();
        else return a < b;
    });
    
    for (int i = 0; i < n; i++) {
        if (s == str[i]) continue;
        
        cout << str[i] << "\n";
        s = str[i];
    }
    
    return 0;
}
