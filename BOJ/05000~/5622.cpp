#include <bits/stdc++.h>

int main() {
    int ans = 0, alphabet[8] = {2, 5, 8, 11, 14, 18, 21, 25};
    std::string s;
    std::cin >> s;
    
    ans += s.size();
    for (int i = 0; i < s.size(); i++) {
        for (int j = 0; j < 8; j++) {
            if (s[i] - 'A' <= alphabet[j]) {
                ans += j+2;
                break;
            }
        }
    }
    
    printf("%d", ans);
    
    return 0;
}