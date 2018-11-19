#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, ans = 0;
    string s;
    bool isUsed[26];
    cin >> n;
    
    for (int i = 0; i < n; i++) {
        cin >> s;
        
        for (int h = 0; h < 26; h++)
            isUsed[h] = false;
        if (s.size() != 1) {   
            for (int j = 0; j < s.size() - 1; j++) {
                if (s[j] != s[j+1]) {
                    if (!isUsed[s[j] - 'a'] && !isUsed[s[j + 1] - 'a'])
                        isUsed[s[j] - 'a'] = true;
                    else
                        break;
                }

                if (j == s.size() - 2)
                    ans++;
            }
        }
        else
            ans++;
    }
    
    printf("%d", ans);
    
    return 0;
}