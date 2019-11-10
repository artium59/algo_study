#include <cstdio>

inline int min(int a, int b) { return a < b ? a : b; }

int v, e, a, b, c, ans=1e9, dist[400][400];

int main() {
    for (int i = 0; i < 400; ++i) {
        for (int k = 0; k < 400; ++k)
            dist[i][k] = 1e9;
    }

    scanf("%d %d", &v, &e);
    while (e--) {
        scanf("%d %d %d", &a, &b, &c);
        dist[a-1][b-1] = c;
    }

    for (int k = 0; k < v; ++k) {
        for (int i = 0; i < v; ++i) {
            for (int j = 0; j < v; ++j)
                dist[i][j] = min(dist[i][j], dist[i][k]+dist[k][j]);
        }
    }

    for (int i = 0; i < v; i++)
        ans = min(ans, dist[i][i]);

    ans = ans == 1e9 ? -1 : ans;
    printf("%d", ans);

    return 0;
}
