#include <cstdio>
#include <algorithm>

int n, l, r, m, height[100000], order[100000], ans[100000], tree[262144];

inline int min(int a, int b) { return a < b ? a : b; }

int init(int node, int start, int end) {
    if (start >= end) return tree[node] = 1;
    return tree[node] = init(node*2, start, (start+end)/2) +
                        init(node*2+1, (start+end)/2+1, end);
}

int update(int node, int start, int end, int loc) {
    if (end < loc || loc < start) return tree[node];
    if (start >= end) return tree[node] = 0;

    return tree[node] = update(node*2, start, (start+end)/2, loc) +
                        update(node*2+1, (start+end)/2+1, end, loc);
}

int query(int node, int start, int end, int loc) {
    if (loc < start) return 0;
    if (end <= loc) return tree[node];

    return query(node*2, start, (start+end)/2, loc) +
           query(node*2+1, (start+end)/2+1, end, loc);
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
        scanf("%d", height+i);
    for (int i = 0; i < n; ++i)
        scanf("%d", order+i);

    init(1, 0, n-1);
    std::sort(height, height+n);

    for (int i = n-1; i >= 0; --i) {
        l = 0; r = n-1;
        while (l <= r) {
            m = (l + r) / 2;
            if (query(1, 0, n-1, m) <= order[i]) l = m+1;
            else r = m-1;
        }

        ans[i] = height[l];
        update(1, 0, n-1, l);
    }

    for (int i = 0; i < n; ++i)
        printf("%d\n", ans[i]);

    return 0;
}
