#include <bits/stdc++.h>

int main() {
    int t;
    scanf("%d", &t);
    
    for (int h = 0; h < t; h++) {
        int ans = 0;
        bool isAnswer = true;;
        std::string str;
        std::cin >> str;
        
        for (const auto& s : str) {
            if (s == '(') ans++;
            else ans--;
            
            if (ans < 0) {
                isAnswer = false;
                break;
            }
        }
        
        printf((isAnswer && ans == 0) ? "YES\n" : "NO\n");
    }
    
    return 0;
}