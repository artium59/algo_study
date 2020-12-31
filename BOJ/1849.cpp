#include <cstdio>

const int MAX = 100000;
int n, a, arr[MAX], tree[262144];

int init(int node, int start, int end) {
    if (start >= end) return tree[node] = 1;

    return tree[node] = init(node*2, start, (start+end)/2) +
                        init(node*2+1, (start+end)/2+1, end);
}

void update(int node, int start, int end, int loc) {
    if (loc < start || end < loc) return;

    --tree[node];
    if (start >= end) return;

    update(node*2, start, (start+end)/2, loc);
    update(node*2+1, (start+end)/2+1, end, loc);
}

int query(int node, int start, int end, int num) {
    if (start >= end) return start;

    int mid = (start + end) / 2;
    if (tree[node*2] > num) return query(node*2, start, mid, num);
    else return query(node*2+1, mid+1, end, num-tree[node*2]);
}

int main() {
    scanf("%d", &n);
    init(1, 0, n-1);

    for (int i = 0; i < n; ++i) {
        scanf("%d", &a);
        a = query(1, 0, n-1, a);
        arr[a] = i+1;
        update(1, 0, n-1, a);
    }

    for (int i = 0; i < n; ++i)
        printf("%d\n", arr[i]);

    return 0;
}
