#include <iostream>
#include <cstring>

const int xrr[4] = { 1, -1, 0, 0 }, yrr[4] = { 0, 0, 1, -1 };
int t, m, n, k, a, b;
bool cabbage[50][50];

void DFS(int b, int a) {
    int nx, ny;
    cabbage[b][a] = false;

    for (int i = 0; i < 4; i++) {
        ny = b+yrr[i]; nx = a + xrr[i];
        if (-1 < ny && ny < n && -1 < nx && nx < m && cabbage[ny][nx])
            DFS(ny, nx);
    }
}

int main() {
    scanf("%d", &t);
    for (int h = 0; h < t; h++) {
        memset(cabbage, false, sizeof(cabbage));

        scanf("%d %d %d", &m, &n, &k);
        for (int i = 0; i < k; i++) {
            scanf("%d %d", &a, &b);
            cabbage[b][a] = true;
        }

        a = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (cabbage[i][j]) {
                    DFS(i, j); a++;
                }
            }
        }

        printf("%d\n", a);
    }

    return 0;
}