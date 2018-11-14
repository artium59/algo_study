#include <bits/stdc++.h>

int main() {
    std::string a, b;
    std::cin >> a >> b;
    int ans = a.size() + b.size();
    
    for (int i = 0; i < a.size(); i++) {
        for (int j = 0; j < b.size(); j++) {
            if (a[i] == b[j]) {
                a.erase(a.begin() + i);
                b.erase(b.begin() + j);
                i--;
                break;
            }
        }
    }
    
    printf("%d", (int)(a.size() + b.size()));
    
    return 0;
}