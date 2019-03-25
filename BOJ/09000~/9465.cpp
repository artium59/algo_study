#include <iostream>

int stickers[2][100000];

int max(int a, int b) {
    return a > b ? a : b;
}

int main() {
    int t, n;

    scanf("%d", &t);
    for (int h = 0; h < t; h++) {
        scanf("%d", &n);
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < n; j++)
                scanf("%d", &stickers[i][j]);
        }

        stickers[0][1] += stickers[1][0];
        stickers[1][1] += stickers[0][0];
        for (int i = 2; i < n; i++) {
            stcikers[0][i] += max(stickers[1][i-1], stickers[1][i-2]);
            stickers[1][i] += max(stickers[0][i-1], stickers[0][i-2]);
        }

        printf("%d\n", max(stickers[0][n-1], stickers[1][n-1]));
    }

    return 0;
}
