#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n;
string s;
vector<string> v;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    for (int i = 1; ; i++) {
        getline(cin, s);
        n = stoi(s, nullptr);
        if (n == 0) break;
        
        for (int i = 0; i < n; i++) {
            getline(cin, s);
            v.push_back(s);
        }
        
        sort(v.begin(), v.end());
        
        cout << i << "\n";
        for_each(v.begin(), v.end(), [](const auto& a) { cout << a << "\n"; });
        v.clear();
    }

    return 0;
}
