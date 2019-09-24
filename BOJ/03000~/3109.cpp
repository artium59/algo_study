#include <stdio.h>

int r, c, ans=0;
char pipe[10000][500];

bool dfs(int y, int x) {
    if (x == c-1) return true;
    
    bool ret = false;
    
    if (!ret && y > 0 && pipe[y-1][x+1] == '.') {
        pipe[y-1][x+1] = 'x';
        ret = dfs(y-1, x+1);
    }
    
    if (!ret && pipe[y][x+1] == '.') {
        pipe[y][x+1] = 'x';
        ret = dfs(y, x+1);
    }
    
    if (!ret && y < r && pipe[y+1][x+1] == '.') {
        pipe[y+1][x+1] = 'x';
        ret = dfs(y+1, x+1);
    }
    
    return ret;
}

int main() {
    scanf("%d %d", &r, &c);
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++)
            scanf(" %c", &pipe[i][j]);
    }
    
    for (int i = 0; i < r; i++) ans += dfs(i, 0);

    printf("%d", ans);

    return 0;
}
