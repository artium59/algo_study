#include <iostream>

int relation[100][100];

int main() {
    int n, m, a, b, ans;

    for (int i = 0; i < 100; i++) {
        for (int j = 0; j < 100; j++) {
            if (i == j) relation[i][j] = 0;
            else relation[i][j] = 987654321;
        }
    }

    scanf("%d %d", &n ,&m);
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &a, &b);
        relation[a-1][b-1] = 1;
        relation[b-1][a-1] = 1;
    }

    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (relation[i][j] > relation[i][k] + relation[k][j])
                    relation[i][j] = relation[i][k] + relation[k][j];
            }
        }
    }

    a = 987654321;
    for (int i = 0; i < n; i++) {
        b = 0;
        for (int j = 0; j < n; j++)
            b += relation[i][j];
        if (a > b) {
            a = b; ans = i;
        }
    }

    printf("%d", ans+1);

    return 0;
}