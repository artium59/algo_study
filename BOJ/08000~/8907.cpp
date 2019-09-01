#include <stdio.h>

int t, u, n, a, sum, dot[1000][1000];

int main() {
    scanf("%d", &t);
    while (t--) {
        sum = 0;
        scanf("%d", &n);
        
        for (int i = 0; i < n; i++) {
            for (int j = i+1; j < n; j++) {
                scanf("%d", &dot[i][j]);
                dot[j][i] = dot[i][j];
            }
            
            a = 0;
            for (int j = 0; j < n; j++) {
                a += (dot[i][j] == 1);
            }
            
            sum += a*(n-a-1);
        }
        
        printf("%d\n", n*(n-1)*(n-2)/6 - sum/2);
    }

    return 0;
}
