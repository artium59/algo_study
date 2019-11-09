#include <cstdio>

const int MAX=1e9+3;
int n, k, color[1001][1001];

int main() {
    scanf("%d %d", &n, &k);
    for (int j = 1; j <= k; ++j)
        for (int i = 2; i <= n; ++i) {
            if (j == 1) color[i][j] = i;
            else color[i][j] = (color[i-1][j]+color[i-2][j-1])%MAX;
    }
    
    printf("%d", color[n][k]);

    return 0;
}
