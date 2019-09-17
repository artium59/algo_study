#include <cstdio>

char change(char ch) {
    char ret;
    
    if (ch == '-') ret = '|';
    else if (ch == '|') ret = '-';
    else if (ch == '/') ret = '\\';
    else if (ch == '\\') ret = '/';
    else if (ch == '^') ret = '<';
    else if (ch == '<') ret = 'v';
    else if (ch == 'v') ret = '>';
    else if (ch == '>') ret = '^';
    else ret = ch;
    
    return ret;
}

int main() {
    int n, m;
    char grid[100][100];
    
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            scanf(" %c", &grid[i][j]);
    }
    
    for (int j = m; j > 0; j--) {
        for (int i = 0; i < n; i++)
            printf("%c", change(grid[i][j-1]));
        printf("\n");
    }

    return 0;
}
