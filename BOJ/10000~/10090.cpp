#include <cstdio>

const int MAX = 1000000;
int n, t, tree[2097152];
long long ans;

void update(int node, int start, int end, int loc) {
    if (end < loc || loc < start) return;

    ++tree[node];
    if (start >= end) return;

    update(node*2, start, (start+end)/2, loc);
    update(node*2+1, (start+end)/2+1, end, loc);
}

int query(int node, int start, int end, int left, int right) {
    if (end < left || right < start) return 0;
    if (left <= start && end <= right) return tree[node];

    return query(node*2, start, (start+end)/2, left, right) +
           query(node*2+1, (start+end)/2+1, end, left, right);
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &t);
        ans += query(1, 0, MAX, t+1, MAX);
        update(1, 0, MAX, t);
    }

    printf("%lld", ans);
    return 0;
}
