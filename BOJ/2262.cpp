#include <bits/stdc++.h>

int main() {
    int n, t, ans = 0;
    std::vector<int> tor;
    scanf("%d", &n);
    
    for (int h = 0; h < n; h++) {
        scanf("%d", &t);
        tor.push_back(t);
    }
    
    while (tor.size() > 1) {
        int location;
        
        for (int i = 0; i < tor.size(); i++) {
            if (tor[i] == tor.size()) {
                location = i;
                break;
            }
        }
        
        if (location + 1 < tor.size()) {
            if (tor[location - 1] > tor[location + 1])
                ans += tor[location] - tor[location - 1];
            else
                ans += tor[location] - tor[location + 1];
        } else
            ans += tor[location] - tor[location - 1];
        
        tor.erase(tor.begin() + location);
    }
    
    printf("%d", ans);
    
    return 0;
}