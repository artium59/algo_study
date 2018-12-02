#include <bits/stdc++.h>

int main() {
    int n, s, r, t, ans = 0, team[10];
    scanf("%d %d %d", &n, &s, &r);
    
    for (int a = 0; a < n; a++)
        team[a] = 1;
    
    for (int b = 0; b < s; b++) {
        scanf("%d", &t);
        team[t-1] -= 1;
    }
    
    for (int c = 0; c < r; c++) {
        scanf("%d", &t);
        team[t-1] += 1;
    }
    
    for (int d = 0; d < n-1; d++) {
        if ((team[d] + team[d+1]) == 2) {
            team[d] = 1;
            team[d+1] = 1;
        }
    }
    
    for (int e = 0; e < n; e++) {
        if (team[e] == 0)
            ans++;
    }
    
    printf("%d", ans);
    
    return 0;
}