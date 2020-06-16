#include <cstdio>
using ll = long long;

int n, q, a, b, c;
ll d, tree[2097152];

ll update(int node, int start, int end, int loc, ll plus) {
    if (end < loc || loc < start) return tree[node];
    if (start >= end) return tree[node] += plus;

    return tree[node] = update(node*2, start, (start+end)/2, loc, plus) +
                        update(node*2+1, (start+end)/2+1, end, loc, plus);
}

ll query(int node, int start, int end, int left, int right) {
    if (right < start || end < left) return 0;
    if (left <= start && end <= right) return tree[node];
    if (start >= end) return tree[node];

    return query(node*2, start, (start+end)/2, left, right) +
            query(node*2+1, (start+end)/2+1, end, left, right);
}

int main(void) {
    scanf("%d %d", &n, &q);
    while (q--) {
        scanf("%d", &a);
        if (a == 1) {
            scanf("%d %lld", &b, &d);
            update(1, 0, n-1, b-1, d);
        }
        else {
            scanf("%d %d", &b, &c);
            printf("%lld\n", query(1, 0, n-1, b-1, c-1));
        }
    }

    return 0;
}
