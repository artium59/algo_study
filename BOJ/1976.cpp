#include <cstdio>

inline int max(int a, int b) { return a > b ? a : b; }

int n, m, t, parent[200];
bool imp;

int Find(int a) {
    if (a == parent[a]) return a;
    else return parent[a] = Find(parent[a]);
}

void Union(int a, int b) {
    int fa = Find(a), fb = Find(b);
    if (fa != fb) parent[max(fa, fb)] = -max(-fa, -fb);
}

int main() {
    for (int i = 0; i < 200; i++) parent[i] = i;

    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &t);
            if (t == 1) Union(i, j);
        }
    }

    n = -1;
    while (m--) {
        scanf("%d", &t);

        if (n == -1)
            n = parent[t-1];
        else {
            if (n != parent[t-1]) { imp = true; break; }
        }
    }

    printf(imp ? "NO" : "YES");

    return 0;
}
