#include <bits/stdc++.h>

int main() {
    int n, a, b, c, d;
    std::vector<int> cal;
    
    scanf("%d %d %d %d", &n, &a, &b, &c);
    for (int i = 0; i < n; i++) {
        scanf("%d", &d);
        cal.push_back(d);
    }
    
    sort(cal.begin(), cal.end(), std::greater<int>());
    int maximum = c / a;
    for (int j = 0; j < n; j++) {
        c += cal[j];
        if (maximum > c/(a+b*(j+1)))
            break;
        else
            maximum = c/(a+b*(j+1));
    }
    
    printf("%d", maximum);
    
    return 0;
}