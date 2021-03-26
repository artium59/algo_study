#include <cstdio>
using ll = long long;

int n, arr[100000], tree[262144];

inline ll max(ll a, ll b) { return a > b ? a : b; }

ll init(int node, int start, int end) {
    if (start >= end) return tree[node] = start;

    int l = init(node*2, start, (start+end)/2);
    int r = init(node*2+1, (start+end)/2+1, end);

    return tree[node] = arr[l] < arr[r] ? l : r;
}

ll query(int node, int start, int end, int left, int right) {
    if (end < left || right < start) return -1;
    if (left <= start && end <= right) return tree[node];

    int l = query(node*2, start, (start+end)/2, left, right);
    int r = query(node*2+1, (start+end)/2+1, end, left, right);

    if (l == -1) return r;
    else if (r == -1) return l;
    else return arr[l] < arr[r] ? l : r;
}

ll find(int left, int right) {
    int q = query(1, 0, n-1, left, right);
    ll ret = (ll) (right-left+1) * arr[q];

    if (left < q)
        ret = max(ret, find(left, q-1));
    if (q < right)
        ret = max(ret, find(q+1, right));

    return ret;
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
        scanf("%d", arr+i);

    init(1, 0, n-1);
    printf("%lld", find(0, n-1));

    return 0;
}
