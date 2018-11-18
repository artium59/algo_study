#include <bits/stdc++.h>

int main() {
    std::string s;
    std::cin >> s;
    
    for (int i = 1; i < s.size() + 1; i++) {
        std::cout << s[i - 1];
        if (i > 0 && i % 10 == 0) 
            std::cout << std::endl;
    }
    
    return 0;
}