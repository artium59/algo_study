#include <bits/stdc++.h>

int main() {
    int n, t, ans = 0;
    bool seats[100];
    std::vector<int> guests;
    scanf("%d", &n);
    
    for (int h = 0; h < 100; h++)
        seats[h] = false;
    
    for (int h = 0; h < n; h++) {
        scanf("%d", &t);
        guests.push_back(t);
    }
    
    for (int i = 0; i < n; i++) {
        if (!seats[guests[i]-1])
            seats[guests[i]-1] = true;
        else
            ans++;
    }
    
    printf("%d", ans);
    
    return 0;
}