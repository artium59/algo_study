#include <bits/stdc++.h>

int main() {
    int m, x, y;
    bool cup[3] = {true, false, false};
    scanf("%d", &m);
    
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &x, &y);
        x--; y--;
        
        if (cup[x] != cup[y]) {
            cup[x] = !cup[x];
            cup[y] = !cup[y];
        }
        else
            continue;
    }
    
    for (int j = 0; j < 3; j++) {
        if (cup[j]) {
            printf("%d", j+1);
            break;
        }
    }
    
    return 0;
}