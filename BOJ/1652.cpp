#include <bits/stdc++.h>

int main() {
    int n, xAns = 0, yAns = 0;
    char c;
    scanf("%d", &n);
    bool room[n][n];
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            std::cin >> c;
            room[i][j] = (c == '.') ? true : false;
        }
    }
    
    for (int y = 0; y < n; y++) {
        bool check = false;
        int column = 0;
        for (int x = 0; x < n; x++) {
            if (room[y][x]) {
                if (!check) check = true;
                column++;
            }
            else {
                if (column > 1) xAns++;
                check = false;
                column = 0;
            }
        }
        if (column > 1) xAns++;
    }
    
    for (int x = 0; x < n; x++) {
        bool check = false;
        int row = 0;
        for (int y = 0; y < n; y++) {
            if (room[y][x]) {
                if (!check) check = true;
                row++;
            }
            else {
                if (row > 1) yAns++;
                check = false;
                row = 0;
            }
        }
        if (row > 1) yAns++;
    }
    
    /* printf("\n\n");
    for (int y = 0; y < n; y++) {
        for (int x = 0; x < n; x++)
            printf(room[y][x] ? "." : "X");
        printf("\n");
    } */
    
    printf("%d %d", xAns, yAns);
    
    return 0;
}