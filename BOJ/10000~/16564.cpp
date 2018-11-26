#include <bits/stdc++.h>

int main() {
    int n, k, t;
    std::vector<int> lv, gap;
    scanf("%d %d", &n, &k);
    
    for (int h = 0; h < n; h++) {
        scanf("%d", &t);
        lv.push_back(t);
    }
    
    sort(lv.begin(), lv.end());
    
    for (int i = 1; i < n; i++) {
        gap.push_back((lv[i] - lv[i-1])*i);
    }
    
    for (int j = 0; j < n-1; j++) {
        if (k <= 0) break;
        
        if (k >= gap[j]) {
            k -= gap[j];
            lv[0] += gap[j]/(j+1);
        }
        else if (k/(j+1) >= 1) {
            lv[0] += k/(j+1);
            break;
        }
    }
    
    printf("%d", lv[0]);
    
    return 0;
}