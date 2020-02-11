#include <cstdio>
using ll = long long;

const ll MAX = 1000000007LL;
int n, m, k, a, b, c, arr[1000000];
ll tree[2097152];

ll init(int node, int start, int end) {
    if (start >= end) return tree[node] = arr[start];

    return tree[node] = (init(node*2, start, (start+end)/2) *
                        init(node*2+1, (start+end)/2+1, end)) % MAX;
}

ll update(int node, int start, int end, int loc, int num) {
    if (end < loc || loc < start) return tree[node];
    if (start >= end) return tree[node] = num;

    return tree[node] = (update(node*2, start, (start+end)/2, loc, num) *
                        update(node*2+1, (start+end)/2+1, end, loc, num)) % MAX;
}

ll search(int node, int start, int end, int left, int right) {
    if (right < start || end < left) return 1;
    if (left <= start && end <= right) return tree[node];

    return (search(node*2, start, (start+end)/2, left, right) *
            search(node*2+1, (start+end)/2+1, end, left, right)) % MAX;
}

int main() {
    scanf("%d %d %d", &n, &m, &k);
    for (int i = 0; i < n; ++i)
        scanf("%d", arr+i);

    init(1, 0, n-1);
    for (int i = 0; i < m+k; ++i) {
        scanf("%d %d %d", &a, &b, &c);

        if (a == 1) update(1, 0, n-1, b-1, c);
        else printf("%d\n", search(1, 0, n-1, b-1, c-1));
    }

    return 0;
}
