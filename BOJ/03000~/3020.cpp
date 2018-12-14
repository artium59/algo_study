#include <bits/stdc++.h>

int main() {
    int n, h, t, ansCount = 0;
    scanf("%d %d", &n, &h);
    std::vector<int> stalagmites(h, 0), stalactites(h, 0);
    
    for (int i = 0; i < n; i++) {
        scanf("%d", &t);
        if (i % 2 == 0)
            stalagmites[t-1] += 1;
        else
            stalactites[t-1]++;
    }
    
    for (int i = h-1; i > 0; i--) {
        stalagmites[i-1] += stalagmites[i];
        stalactites[i-1] += stalactites[i];
    }
    
    for (int j = 0; j < h; j++)
        stalagmites[j] += stalactites[h-j-1];
    
    sort(stalagmites.begin(), stalagmites.end());
    
    for (int k = 0; k < h; k++) {
        if (stalagmites[0] == stalagmites[k])
            ansCount++;
    }
    
    printf("%d %d", stalagmites[0], ansCount);
    
    return 0;
}