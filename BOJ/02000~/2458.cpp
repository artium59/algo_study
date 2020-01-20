#include <cstdio>

int n, m, a, b;
bool graph[500][500];

int main() {
    scanf("%d %d", &n, &m);
    while (m--) {
        scanf("%d %d", &a, &b); --a; --b;
        graph[a][b] = true;
    }

    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (!graph[i][j])
                    graph[i][j] = graph[i][k] && graph[k][j];
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        a = 0;
        
        for (int j = 0; j < n; ++j) {
            if (graph[i][j] || graph[j][i]) ++a;
        }
        if (a == n-1) ++m;
    }

    printf("%d", m+1);

    return 0;
}
