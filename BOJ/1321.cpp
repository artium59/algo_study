#include <cstdio>

const int MAX = 500000;
int n, m, i, a, c, army[MAX], tree[1048576];

int init(int node, int start, int end) {
    if (start >= end) return tree[node] = army[start];

    return tree[node] = init(node*2, start, (start+end)/2) +
                        init(node*2+1, (start+end)/2+1, end);
}

void update(int node, int start, int end, int loc, int num) {
    if (loc < start || end < loc) return;

    tree[node] += num;
    if (start >= end) return;

    update(node*2, start, (start+end)/2, loc, num);
    update(node*2+1, (start+end)/2+1, end, loc, num);
}

int query(int node, int start, int end, int cnt) {
    if (start >= end) return start;

    int mid = (start + end) / 2;
    if (tree[node*2] >= cnt) return query(node*2, start, mid, cnt);
    else return query(node*2+1, mid+1, end, cnt-tree[node*2]);
}

int main() {
    scanf("%d", &n);
    for (int k = 0; k < n; k++)
        scanf("%d", army+k);
    init(1, 0, n-1);

    scanf("%d", &m);
    while (m--) {
        scanf("%d", &c);
        if (c == 1) {
            scanf("%d %d", &i, &a);
            update(1, 0, n-1, i-1, a);
        }
        else {
            scanf("%d", &i);
            printf("%d\n", query(1, 0, n-1, i)+1);
        }
    }

    return 0;
}
