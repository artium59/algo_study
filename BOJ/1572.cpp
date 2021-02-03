#include <cstdio>

const int MAX = 65536;
int n, k, arr[250000], tree[262144];
long long ans;

void update(int node, int start, int end, int loc, bool is_add) {
    if (end < loc || loc < start) return;

    tree[node] += is_add ? 1 : -1;
    if (start >= end) return;

    update(node*2, start, (start+end)/2, loc, is_add);
    update(node*2+1, (start+end)/2+1, end, loc, is_add);
}

int query(int node, int start, int end, int num) {
    if (start >= end) return start;

    int mid = (start + end) / 2;
    if (tree[node*2] >= num) return query(node*2, start, mid, num);
    else return query(node*2+1, mid+1, end, num-tree[node*2]);
}

int main() {
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; ++i) {
        scanf("%d", arr+i);

        update(1, 0, MAX, arr[i], true);
        if (i+1 < k) continue;

        ans += query(1, 0, MAX, (k+1)/2);
        update(1, 0, MAX, arr[i-k+1], false);
    }

    printf("%lld", ans);
    return 0;
}
