#include <iostream>
using ll = long long;

int n, m, a, b, c;
ll d, tree[2097152];

ll update(int node, int start, int end, int loc, ll num) {
    if (end < loc || loc < start) return tree[node];
    if (start >= end) return tree[node] = num;
    return tree[node] = update(node*2, start, (start+end)/2, loc, num) +
                        update(node*2+1, (start+end)/2+1, end, loc, num);
}

ll query(int node, int start, int end, int left, int right) {
    if (right < start || end < left) return 0;
    if (left <= start && end <= right) return tree[node];
    if (start >= end) return tree[node];

    return query(node*2, start, (start+end)/2, left, right) +
            query(node*2+1, (start+end)/2+1, end, left, right);
}

int main(void) {
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; ++i) {
        scanf("%d", &a);
        if (a == 0) {
            scanf("%d %d", &b, &c);
            if (b > c) std::swap(b, c);
            printf("%lld\n", query(1, 0, n-1, b-1, c-1));
        }
        else {
            scanf("%d %lld", &b, &d);
            update(1, 0, n-1, b-1, d);
        }
    }

    return 0;
}
