#include <bits/stdc++.h>

using namespace std;

int main() {
    int testCase, c;
    string s;
    
    cin >> testCase;
    
    for (int i = 0; i < testCase; i++) {
        cin >> c >> s;
        
        for (int a = 0; a < s.size(); a++) {
            for (int b = 0; b < c; b++) {
                cout << s[a];
            }
        }
        cout << endl;
    }
    
    return 0;
}