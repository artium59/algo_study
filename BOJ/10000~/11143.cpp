#include <cstdio>
#include <cstring>

int t, b, p, q, x, y, tree[262144];
char ch;

int update(int node, int start, int end, int loc, int plus) {
    if (end < loc || loc < start) return tree[node];
    if (start >= end) return tree[node] += plus;

    return tree[node] = update(node*2, start, (start+end)/2, loc, plus) +
                        update(node*2+1, (start+end)/2+1, end, loc, plus);
}

int query(int node, int start, int end, int left, int right) {
    if (right < start || end < left) return 0;
    if (left <= start && end <= right) return tree[node];
    if (start >= end) return tree[node];

    return query(node*2, start, (start+end)/2, left, right) +
            query(node*2+1, (start+end)/2+1, end, left, right);
}

int main(void) {
    scanf("%d", &t);
    while (t--) {
        memset(tree, 0, sizeof(tree));

        scanf("%d %d %d", &b, &p, &q);
        for (int i = 0; i < p+q; ++i) {
            scanf(" %c %d %d", &ch, &x, &y);
            if (ch == 'P') update(1, 0, b-1, x-1, y);
            else printf("%d\n", query(1, 0, b-1, x-1, y-1));
        }
    }

    return 0;
}
