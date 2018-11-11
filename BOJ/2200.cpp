#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, f, ans = 0;
    vector<int> formula;
    
    scanf("%d", &n);
    
    for (int a = 0; a < n + 1; a++) {
        scanf("%d", &f);
        formula.push_back(f);
    }
    
    ans += (2 * n - 1);
    
    for (int b = 1; b < n + 1; b++) {
        int power = 0, p = 0;
        
        if (formula[b] != 0) {
            while (formula[b] >= power)
                power = pow(10, ++p);
            
            ans += (p + 1);
        }
    }
    
    printf("%d", ans + 1);
    
    return 0;
}