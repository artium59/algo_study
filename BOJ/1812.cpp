#include <bits/stdc++.h>

int main() {
    int n, k;
    scanf("%d", &n);
    int candy[n], ans[n];
    
    for (int i = 0; i < n; i++)
        scanf("%d", &candy[i]);
    
    for (int j = 0; j <= candy[0]; j++) {
        ans[0] = j;
        for (k = 0; k < n-1; k++) {
            if (candy[k] - ans[k] >= 0)
                ans[k+1] = candy[k] - ans[k];
            else
                break;
        }
        
        if (k == n-1) {
            if (ans[n-1] + ans[0] == candy[n-1])
                break;
        }
    }
    
    for (int l = 0; l < n; l++)
        printf("%d ", ans[l]);
    
    return 0;
}