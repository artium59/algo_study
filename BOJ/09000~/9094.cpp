#include <cstdio>

int main() {
    int tc, ans, n, m;
    
    scanf("%d", &tc);
    while (tc--) {
        ans = 0;
        scanf("%d %d", &n, &m);
        
        for (int i = 1; i < n; i++) {
            for (int j = i+1; j < n; j++) {
                if ((i*i + j*j + m) % (i*j) == 0) ans++;
            }
        }
        
        printf("%d\n", ans);
    }

    return 0;
}
