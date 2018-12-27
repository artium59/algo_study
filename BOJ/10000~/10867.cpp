#include <iostream>

int main() {
    int n, t;
    bool isUsed[2001];
    scanf("%d", &n);
    
    std::fill(isUsed, isUsed+2001, false);
    
    for (int h = 0; h < n; h++) {
        scanf("%d", &t);
        isUsed[t+1000] = true;
    }
    
    for (int i = 0; i < 2001; i++) {
        if (isUsed[i]) printf("%d ", i-1000);
    }
    
    return 0;
}
