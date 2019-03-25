#include <cstdio>
#include <cstring>

int n, m, k, x = 0, y = 0;
long long map[16][16];

void Search(int b, int a, int idx) {
    for (int i = b; i < n; i++) map[i][a] = idx;
    for (int i = a; i < m; i++) map[b][i] = idx;
    
    for (int i = b+1; i < n; i++) {
        for (int j = a+1; j < m; j++)
            map[i][j] = map[i-1][j] + map[i][j-1];
    }
}

int main() {
    memset(map, 0, sizeof(map));
    scanf("%d %d %d", &n, &m, &k);
	
    while (k > 0) {
        if (k-m > 0) y++;
        else x = k-1;
        
        k -= m;
    }
    
    Search(0, 0, 1);
    if (k <= 0) Search(y, x, map[y][x]);

    printf("%lld", map[n-1][m-1]);

    return 0;
}
