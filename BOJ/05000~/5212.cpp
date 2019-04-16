#include <iostream>

int r, c, up, down, left, right, i, j;
char island[12][12];

void Init() {
    for (i = 0; i < 12; i++) {
        for (j = 0; j < 12; j++)
            island[i][j] = '.';
    }
}

bool isFlooded(int y, int x) {
    int cnt = 0;

    if (island[y-1][x] == '.') cnt++;
    if (island[y+1][x] == '.') cnt++;
    if (island[y][x-1] == '.') cnt++;
    if (island[y][x+1] == '.') cnt++;

    return cnt > 2;
}

int main() {
    Init();

    scanf("%d %d", &r, &c);
    for (i = 1; i <= r; i++) {
        for (j = 1; j <= c; j++)
            scanf(" %c", &island[i][j]);
    }

    for (i = 1; i <= r; i++) {
        for (j = 1; j <= c; j++) {
            if (island[i][j] == 'X' && isFlooded(i, j))
                island[i][j] = ',';
        }
    }

    for (i = 1; i <= r; i++) {
        for (j = 1; j <= c; j++) {
            if (island[i][j] == 'X') {
                up = i; break;
            }
        }
        if (island[i][j] == 'X') break;
    }

    for (j = 1; j <= c; j++) {
        for (i = 1; i <= r; i++) {
            if (island[i][j] == 'X') {
                left = j; break;
            }
        }
        if (island[i][j] == 'X') break;
    }
    
    for (i = r; i > 0; i--) {
        for (j = c; j > 0; j--) {
            if (island[i][j] == 'X') {
                down = i; break;
            }
        }
        if (island[i][j] == 'X') break;
    }

    for (j = c; j > 0; j--) {
        for (i = r; i > 0; i--) {
            if (island[i][j] == 'X') {
                right = j; break;
            }
        }
        if (island[i][j] == 'X') break;
    }

    for (i = up; i <= down; i++) {
        for (j = left; j <= right; j++) {
            if (island[i][j] == ',') island[i][j] = '.';
            printf("%c", island[i][j]);
        }
        printf("\n");
    }

    return 0;
}
