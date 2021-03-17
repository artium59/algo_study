#include <cstdio>

int n, k, q, cnt, tree[262144];

int init(int node, int start, int end) {
    if (start >= end) return tree[node] = 1;

    return tree[node] = init(node*2, start, (start+end)/2) +
                        init(node*2+1, (start+end)/2+1, end);
}

void update(int node, int start, int end, int loc) {
    if (end < loc || loc < start) return;
    if (start <= loc && loc <= end) --tree[node];
    if (start >= end) return;

    update(node*2, start, (start+end)/2, loc);
    update(node*2+1, (start+end)/2+1, end, loc);
}

int query(int node, int start, int end, int num) {
    if (start >= end) return start;

    if (tree[node*2] >= num)
        return query(node*2, start, (start+end)/2, num);
    else
        return query(node*2+1, (start+end)/2+1, end, num-tree[node*2]);
}

int main() {
    scanf("%d %d", &n, &k);
    init(1, 0, n-1);

    printf("<");
    for (int i = 1; i <= n; ++i) {
        cnt += k;
        while (cnt > tree[1]) {
            cnt -= tree[1];
        }

        q = query(1, 0, n-1, cnt);
        printf("%d", q+1);
        if (i != n) printf(", ");

        update(1, 0, n-1, q);
        --cnt;
    }
    printf(">");

    return 0;
}
