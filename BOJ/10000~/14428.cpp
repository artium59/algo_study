#include <stdio.h>

int n, k, x, y, z, arr[100000], tree[262144];

int init(int node, int start, int end) {
    if (start >= end) return tree[node] = start;

    int a = init(node*2, start, (start+end)/2);
    int b = init(node*2+1, (start+end)/2+1, end);

    return tree[node] = arr[a] <= arr[b] ? a : b;
}

int update(int node, int start, int end, int loc) {
    if (end < loc || loc < start) return tree[node];
    if (start >= end) return tree[node];

    int a = update(node*2, start, (start+end)/2, loc);
    int b = update(node*2+1, (start+end)/2+1, end, loc);

    return tree[node] = arr[a] <= arr[b] ? a : b;
}

int query(int node, int start, int end, int left, int right) {
    if (right < start || end < left) return -1;
    if (left <= start && end <= right) return tree[node];

    int a = query(node*2, start, (start+end)/2, left, right);
    int b = query(node*2+1, (start+end)/2+1, end, left, right);

    if (a == -1) return b;
    else if (b == -1) return a;
    else return arr[a] <= arr[b] ? a : b;
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
        scanf("%d", arr+i);

    init(1, 0, n-1);

    scanf("%d", &k);
    for (int i = 0; i < k; ++i) {
        scanf("%d %d %d", &z, &x, &y);

        if (z == 1) {
            arr[--x] = y;
            update(1, 0, n-1, x);
        }
        else {
            --x; --y;
            printf("%d\n", query(1, 0, n-1, x, y)+1);
        }
    }

    return 0;
}
