#include <cstdio>
#include <tuple>
using namespace std;
using ll = long long;

int n, arr[100000], min_tree[262144];
ll sum_tree[262144];

inline ll max(ll a, ll b) { return a > b ? a : b; }

int min_init(int node, int start, int end) {
    if (start >= end) return min_tree[node] = start;

    int l = min_init(node*2, start, (start+end)/2);
    int r = min_init(node*2+1, (start+end)/2+1, end);

    return min_tree[node] = arr[l] < arr[r] ? l : r;
}

int min_query(int node, int start, int end, int left, int right) {
    if (end < left || right < start) return -1;
    if (left <= start && end <= right) return min_tree[node];

    int l = min_query(node*2, start, (start+end)/2, left, right);
    int r = min_query(node*2+1, (start+end)/2+1, end, left, right);

    if (l == -1) return r;
    else if (r == -1) return l;
    else return arr[l] < arr[r] ? l : r;
}

ll sum_init(int node, int start, int end) {
    if (start >= end) return sum_tree[node] = arr[start];

    return sum_tree[node] = sum_init(node*2, start, (start+end)/2) +
                            sum_init(node*2+1, (start+end)/2+1, end);
}

ll sum_query(int node, int start, int end, int left, int right) {
    if (end < left || right < start) return 0;
    if (left <= start && end <= right) return sum_tree[node];

    return sum_query(node*2, start, (start+end)/2, left, right) +
           sum_query(node*2+1, (start+end)/2+1, end, left, right);
}

tuple<int, int, ll> find(int left, int right) {
    int mq = min_query(1, 0, n-1, left, right);
    tuple<int, int, ll> ret =
            { left, right, (ll) arr[mq] * sum_query(1, 0, n-1, left, right) };

    if (left < mq) {
        auto f = find(left, mq-1);
        if (get<2>(ret) < get<2>(f))
            ret = f;
    }
    if (mq < right) {
        auto f = find(mq+1, right);
        if (get<2>(ret) < get<2>(f))
            ret = f;
    }

    return ret;
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
        scanf("%d", arr+i);

    min_init(1, 0, n-1);
    sum_init(1, 0, n-1);

    auto ret = find(0, n-1);
    printf("%lld\n%d %d", get<2>(ret), get<0>(ret)+1, get<1>(ret)+1);

    return 0;
}
