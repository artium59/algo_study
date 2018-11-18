#include <bits/stdc++.h>

using namespace std;

int main() {
    int t, x, y;
    scanf("%d", &t);
    
    for (int i = 0; i < t; i++) {
        scanf("%d %d", &y, &x);
        vector<string> grill;
        string str;
        
        for (int j = 0; j < y; j++) {
            cin >> str;
            grill.push_back(str);
        }
        
        for (int k = 0; k < y; k++) {
            for (int l = x-1; l >= 0; l--) {
                cout << grill[k][l];
            }
            cout << '\n';
        }
    }
    
    return 0;
}