#include <stdio.h>

int n, k, x, y, z, arr[100000], tree[262144];

inline int min(int a, int b) { return a < b ? a : b; }

int init(int node, int start, int end) {
    if (start >= end) return tree[node] = arr[start];

    return tree[node] = min(init(node*2, start, (start+end)/2),
                            init(node*2+1, (start+end)/2+1, end));
}

int update(int node, int start, int end, int loc, int num) {
    if (end < loc || loc < start) return tree[node];
    if (start >= end) return tree[node] = num;

    return tree[node] = min(update(node*2, start, (start+end)/2, loc, num),
                            update(node*2+1, (start+end)/2+1, end, loc, num));
}

int query(int node, int start, int end, int left, int right) {
    if (right < start || end < left) return 1e9;
    if (left <= start && end <= right) return tree[node];

    return min(query(node*2, start, (start+end)/2, left, right),
                query(node*2+1, (start+end)/2+1, end, left, right));
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
        scanf("%d", arr+i);

    init(1, 0, n-1);

    scanf("%d", &k);
    for (int i = 0; i < k; ++i) {
        scanf("%d %d %d", &z, &x, &y);

        if (z == 1)
            update(1, 0, n-1, x-1, y);
        else {
            --x; --y;
            printf("%d\n", query(1, 0, n-1, x, y));
        }
    }

    return 0;
}
