#include <cstdio>

int n, m, q, i, j, arr[100000];
long long k, tree[262145];

void init(int node, int start, int end) {
    if (start >= end) {
        tree[node] = arr[start];
        return;
    }

    init(node*2, start, (start+end)/2);
    init(node*2+1, (start+end)/2+1, end);
}

void update(int node, int start, int end, int left, int right, long long num) {
    if (right < start || end < left) return;
    if (left <= start && end <= right) {
        tree[node] += num; return;
    }

    update(node*2, start, (start+end)/2, left, right, num);
    update(node*2+1, (start+end)/2+1, end, left, right, num);
}

long long search(int node, int start, int end, int loc) {
    if (loc < start || end < loc) return 0;
    if (start >= end) return tree[node];

    return tree[node] + 
            search(node*2, start, (start+end)/2, loc) +
            search(node*2+1, (start+end)/2+1, end, loc);
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) scanf("%d", arr+i);
    init(1, 0, n-1);

    scanf("%d", &m);
    while (m--) {
        scanf("%d", &q);

        if (q == 1) {
            scanf("%d %d %lld", &i, &j, &k); --i; --j;
            update(1, 0, n-1, i, j, k);
        }
        else {
            scanf("%d", &k); --k;
            printf("%lld\n", search(1, 0, n-1, k));
        }
    }

    return 0;
}
