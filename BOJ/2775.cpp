#include <bits/stdc++.h>

using namespace std;

int main() {
    int apt[15][15];
    int t, k, n;
    
    for (int a = 0; a < 15; a++) {
        apt[0][a] = a + 1;
    }
    
    for (int b = 1; b < 15; b++) {
        for (int c = 0; c < 15; c++) {
            if (c == 0)
                apt[b][0] = apt[b - 1][0];
            else
                apt[b][c] = apt[b][c - 1] + apt[b - 1][c];
        }
    }
    
    scanf("%d", &t);
    for (int i = 0; i < t; i++) {
        scanf("%d", &k);
        scanf("%d", &n);
        
        printf("%d\n", apt[k][n - 1]);
    }
    
    return 0;
}