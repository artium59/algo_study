#include <bits/stdc++.h>

using namespace std;

int main() {
    int a[26];
    string s;
    
    for (int i = 0; i < 26; i++) {
        a[i] = -1;
    }
    
    cin >> s;
    
    for (int j = 0; j < s.size(); j++) {
        if (a[(int)(s[j] - 'a')] == -1)
            a[(int)(s[j] - 'a')] = j;
    }
    
    for (int k = 0; k < 26; k++) {
        cout << a[k] << " "; 
    }
    
    return 0;
}