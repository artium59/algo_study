#include <cstdio>
using ll = long long;

int n, q, a, x, y, t;
ll b, arr[100000], tree[262145];

ll init(int node, int start, int end) {
    if (start >= end) return tree[node] = arr[start];
    return tree[node] = init(node*2, start, (start+end)/2)
                        + init(node*2+1, (start+end)/2+1, end);
}

ll search(int node, int start, int end, int left, int right) {
    if (right < start || end < left) return 0;
    if (left <= start && end <= right) return tree[node];

    return search(node*2, start, (start+end)/2, left, right)
            + search(node*2+1, (start+end)/2+1, end, left, right);
}

void change(int node, ll add, int start, int end, int loc) {
    if (end < loc || loc < start) return;

    tree[node] += add;
    if (start >= end) return;

    change(node*2, add, start, (start+end)/2, loc);
    change(node*2+1, add, (start+end)/2+1, end, loc);
}

int main() {
    scanf("%d %d", &n, &q);
    for (int i = 0; i < n; ++i) scanf("%lld", arr+i);
    init(1, 0, n-1);

    while (q--) {
        scanf("%d %d %d %lld", &x, &y, &a, &b); --x; --y; --a;
        if (x > y) { t = x; x = y; y = t; }
        printf("%lld\n", search(1, 0, n-1, x, y));
        change(1, b-arr[a], 0, n-1, a);
        arr[a] = b;
    }

    return 0;
}
