#include <cstdio>

int n, m, t, a, b, c, arr[500000], tree[1048576];

void init(int node, int start, int end) {
    if (start >= end) {
        tree[node] = arr[start];
        return;
    }

    init(node*2, start, (start+end)/2);
    init(node*2+1, (start+end)/2+1, end);
}

void update(int node, int start, int end, int left, int right, int num) {
    if (right < start || end < left) return;

    if (left <= start && end <= right) {
        tree[node] ^= num;
        return;
    }

    update(node*2, start, (start+end)/2, left, right, num);
    update(node*2+1, (start+end)/2+1, end, left, right, num);
}

int query(int node, int start, int end, int loc) {
    if (end < loc || loc < start) return 0;

    if (start >= end) return tree[node];
    return tree[node] ^ query(node*2, start, (start+end)/2, loc) ^
            query(node*2+1, (start+end)/2+1, end, loc);
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
        scanf("%d", arr+i);

    init(1, 0, n-1);
    scanf("%d", &m);
    while (m--) {
        scanf("%d", &t);
        if (t == 1) {
            scanf("%d %d %d", &a, &b, &c);
            update(1, 0, n-1, a, b, c);
        }
        else {
            scanf("%d", &a);
            printf("%d\n", query(1, 0, n-1, a));
        }
    }

    return 0;
}
