#include <cstdio>
using ll = long long;

int n, m, k, a, b, c, arr[1000000];
ll d, tree[2097152], lazy[2097152];

ll init(int node, int start, int end) {
    if (start >= end) return tree[node] = arr[start];

    return tree[node] = init(node*2, start, (start+end)/2) +
                        init(node*2+1, (start+end)/2+1, end);
}

void update_lazy(int node, int start, int end) {
    if (lazy[node] == 0) return;

    tree[node] += (end-start+1) * lazy[node];

    if (start < end) {
        lazy[node*2] += lazy[node];
        lazy[node*2+1] += lazy[node];
    }
    lazy[node] = 0;
}

ll update(int node, int start, int end, int left, int right, ll num) {
    update_lazy(node, start, end);

    if (end < left || right < start) return tree[node];
    if (left <= start && end <= right) {
        tree[node] += (end-start+1) * num;
        if (start < end) {
            lazy[node*2] += num;
            lazy[node*2+1] += num;
        }
        return tree[node];
    }

    return tree[node] = update(node*2, start, (start+end)/2, left, right, num) +
                        update(node*2+1, (start+end)/2+1, end, left, right, num);
}

ll query(int node, int start, int end, int left, int right) {
    update_lazy(node, start, end);

    if (end < left || right < start) return 0;
    if (left <= start && end <= right) return tree[node];

    return query(node*2, start, (start+end)/2, left, right) +
           query(node*2+1, (start+end)/2+1, end, left, right);
}

int main() {
    scanf("%d %d %d", &n, &m, &k);
    for (int i = 0; i < n; ++i)
        scanf("%d", arr+i);
    init(1, 0, n-1);

    for (int i = 0; i < m+k; ++i) {
        scanf("%d", &a);
        if (a == 1) {
            scanf("%d %d %lld", &b, &c, &d); --b; --c;
            update(1, 0, n-1, b, c, d);
        }
        else {
            scanf("%d %d", &b, &c); --b; --c;
            printf("%lld\n", query(1, 0, n-1, b, c));
        }
    }

    return 0;
}
