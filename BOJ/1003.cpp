#include <bits/stdc++.h>

int main() {
    int t, n, arr[41][2];
    scanf("%d", &t);
    
    arr[0][0] = 1; arr[0][1] = 0;
    arr[1][0] = 0; arr[1][1] = 1;
    
    for (int h = 2; h < 41; h++) {
        arr[h][0] = arr[h-1][0] + arr[h-2][0];
        arr[h][1] = arr[h-1][1] + arr[h-2][1];
    }
    
    for (int i = 0; i < t; i++) {
        scanf("%d", &n);
        printf("%d %d\n", arr[n][0], arr[n][1]);
    }
        
    return 0;
}