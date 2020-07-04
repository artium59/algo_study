#include <cstdio>

const int MAX = 1e6 + 1;
int n, a, b, parent[MAX], cnt[MAX];
char q;

int Find(int x) {
    if (parent[x] == x) return x;
    else return parent[x] = Find(parent[x]);
}

void Union(int x, int y) {
    int fx = Find(x), fy = Find(y);
    if (fx != fy) parent[fx] = fy, cnt[fy] += cnt[fx];
}

int main() {
    for (int i = 1; i < MAX; ++i) parent[i] = i, cnt[i] = 1;

    scanf("%d", &n);
    while (n--) {
        scanf(" %c", &q);
        if (q == 'I') {
            scanf("%d %d", &a, &b);
            Union(a, b);
        }
        else {
            scanf("%d", &a);
            printf("%d\n", cnt[Find(a)]);
        }
    }

    return 0;
}
