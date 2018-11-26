#include <bits/stdc++.h>

int main() {
    int n, t;
    bool isBreak = false;
    float ans = 1;
    std::vector<int> gas, balloon;
    scanf("%d", &n);
    
    for (int h = 0; h < n; h++)
        balloon.push_back(h+1);
    
    for (int h = 0; h < n; h++) {
        scanf("%d", &t);
        gas.push_back(t);
    }
    
    sort(gas.begin(), gas.end());
    
    for (int i = 0; i < n; i++) {
        if (balloon[i] < gas[i]) {
            isBreak = true;
            break;
        }
        else {
            if (ans > (float)gas[i]/(float)balloon[i])
                ans = (float)gas[i]/(float)balloon[i];
        }
    }
    
    if (isBreak)
        printf("impossible");
    else
        printf("%f", ans);
    
    return 0;
}