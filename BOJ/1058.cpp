#include <iostream>

inline int max(int a, int b) { return a > b ? a : b; }

int n, t, ans = 0, graph[50][50];
char ch;

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf(" %c", &ch);
            if (ch == 'Y') graph[i][j] = 1;
            else graph[i][j] = 1000;
        }
    }

    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (graph[i][j] > graph[i][k] + graph[k][j])
                    graph[i][j] = graph[i][k] + graph[k][j];
            }
        }
    }

    for (int i = 0; i < n; i++) {
        t = 0;
        for (int j = 0; j < n; j++) {
            if (0 < graph[i][j] && graph[i][j] < 3) t++;
        }
        ans = max(ans, t-1);
    }

    printf("%d", ans);

    return 0;
}
