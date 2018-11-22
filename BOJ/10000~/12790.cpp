#include <bits/stdc++.h>

int main() {
    int t;
    scanf("%d", &t);
    
    for (int h = 0; h < t; h++) {
        int basic[4], k;
        
        for (int i = 0; i < 4; i++)
            scanf("%d", &basic[i]);
        
        for (int i = 0; i < 4; i++) {
            scanf("%d", &k);
            basic[i] += k;
        }
        
        if (basic[0] < 1)
            basic[0] = 1;
        if (basic[1] < 1)
            basic[1] = 1;
        if (basic[2] < 0)
            basic[2] = 0;
        
        printf("%d\n", basic[0] + 5*basic[1] + 2*basic[2] + 2*basic[3]);
    }
    
    return 0;
}