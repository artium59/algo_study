#include <bits/stdc++.h>

int main() {
    int n;
    scanf("%d", &n);
    int tri[n][n];
    
    for (int i = 0; i < n ; i++) {
        for (int j = 0; j < i+1; j++) {
            scanf("%d", &tri[i][j]);
        }
    }
    
    for (int i = n-2; i > -1; i--) {
        for (int j = 0; j < i+1; j++) {
            if (tri[i+1][j] > tri[i+1][j+1])
                tri[i][j] += tri[i+1][j];
            else
                tri[i][j] += tri[i+1][j+1];
        }
    }
    
    printf("%d", tri[0][0]);
    
    return 0;
}