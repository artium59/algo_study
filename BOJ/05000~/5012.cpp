#include <cstdio>
#include <cstring>

const int MAX = 100000;
int n, arr[MAX], tree[262145];
long long ans, min_cnt[MAX], max_cnt[MAX];

int search(int node, int start, int end, int left, int right) {
    if (right < start || end < left) return 0;
    if (start >= end) return tree[node];
    if (left <= start && end <= right) return tree[node];

    return search(node*2, start, (start+end)/2, left, right) +
            search(node*2+1, (start+end)/2+1, end, left, right);
}

void change(int node, int start, int end, int loc) {
    if (end < loc || loc < start) return;

    ++tree[node];
    if (start >= end) return;

    change(node*2, start, (start+end)/2, loc);
    change(node*2+1, (start+end)/2+1, end, loc);
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", arr+i); --arr[i];
    }

    for (int i = 0; i < n; ++i) {
        max_cnt[i] = search(1, 0, n-1, arr[i]+1, n-1);
        change(1, 0, n-1, arr[i]);
    }
    memset(tree, 0, sizeof(tree));
    for (int i = n-1; i >= 0; --i) {
        min_cnt[i] = search(1, 0, n-1, 0, arr[i]-1);
        change(1, 0, n-1, arr[i]);
    }

    for (int i = 0; i < n; ++i) ans += min_cnt[i] * max_cnt[i];

    printf("%lld", ans);

    return 0;
}
