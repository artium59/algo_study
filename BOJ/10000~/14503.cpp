#include <iostream>

short floor[50][50];

int abs(int a) {
    return a > 0 ? a : -a;
}

int main() {
    int n, m, r, c, d, t;
    bool swch;

    scanf("%d %d", &n, &m);
    scanf("%d %d %d", &r, &c, &d);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &t);
            floor[i][j] = (t == 1 ? -1 : 0);
        }
    }

    t = 0;
    // go left = (d+3)%4
    while (true) {
        if (floor[r][c] == 0) t++;
        floor[r][c] = 1;
        swch = true;

        if (abs(floor[r][c-1]) + abs(floor[r][c+1]) + abs(floor[r-1][c]) + abs(floor[r+1][c]) == 4) {
            if (d == 0) {
                if (floor[r+1][c] == -1) break;
                else r++;
            }
            else if (d == 1) {
                if (floor[r][c-1] == -1) break;
                else c--;
            }
            else if (d == 2) {
                if (floor[r-1][c] == -1) break;
                else r--;
            }
            else {
                if (floor[r][c+1] == -1) break;
                else c++;
            }
            swch = false;
        }

        while (swch) {
            switch(d) {
                case 0:
                    if (floor[r][c-1] == 0) {
                        c--; swch = false;
                    }
                    d = 3;
                    break;
                case 1:
                    if (floor[r-1][c] == 0) {
                        r--; swch = false;
                    }
                    d = 0;
                    break;
                case 2:
                    if (floor[r][c+1] == 0) {
                        c++; swch = false;
                    }
                    d = 1;
                    break;
                case 3:
                    if (floor[r+1][c] == 0) {
                        r++; swch = false;
                    }
                    d = 2;
                    break;
            }
        }
    }

    printf("%d", t);

    return 0;
}