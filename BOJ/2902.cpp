#include <bits/stdc++.h>

int main() {
    std::string s;
    std::cin >> s;
    
    for (int i = 0; i < s.size(); i++) {
        if (i == 0)
            printf("%c", s[i]);
        else if (s[i] == '-')
            printf("%c", s[i+1]);
    }
    
    return 0;
}