#include <cstdio>

int n, s, a, b, arr[401][401];

int main() {
    scanf("%d %d", &n, &s);
    while (s--) {
        scanf("%d %d", &a, &b);
        arr[a][b] = -1;
        arr[b][a] = 1;
    }

    for (int k = 1; k <= n; ++k) {
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (i == j || arr[i][k] == 0 || arr[k][j] == 0) continue;
                if (arr[i][k] == arr[k][j]) arr[i][j] = arr[i][k];
            }
        }
    }

    scanf("%d", &s);
    while (s--) {
        scanf("%d %d", &a, &b);
        printf("%d\n", arr[a][b]);
    }

    return 0;
}
