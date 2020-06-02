#include <cstdio>

int n, m, a, b, c, arr[100000], tree[262144];

int init(int node, int start, int end) {
    if (start >= end) return tree[node] = start;

    int t1 = init(node*2, start, (start+end)/2);
    int t2 = init(node*2+1, (start+end)/2+1, end);

    return tree[node] = arr[t1] <= arr[t2] ? t1 : t2;
}

int update(int node, int start, int end, int loc) {
    if (end < loc || loc < start) return tree[node];
    if (start >= end) return tree[node];

    int t1 = update(node*2, start, (start+end)/2, loc);
    int t2 = update(node*2+1, (start+end)/2+1, end, loc);

    return tree[node] = arr[t1] <= arr[t2] ? t1 : t2;
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
        scanf("%d", arr+i);

    init(1, 0, n-1);
    scanf("%d", &m);
    while (m--) {
        scanf("%d", &a);
        if (a == 1) {
            scanf("%d %d", &b, &c);
            arr[b-1] = c;
            update(1, 0, n-1, b-1);
        }
        else
            printf("%d\n", tree[1]+1);
    }

    return 0;
}
