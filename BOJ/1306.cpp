#include <cstdio>
using namespace std;

int n, m, arr[1000000], tree[2097152];

inline int max(int a, int b) { return a > b ? a : b; }

int init(int node, int start, int end) {
    if (start >= end) return tree[node] = arr[start];
    return tree[node] = max(init(node*2, start, (start+end)/2),
                            init(node*2+1, (start+end)/2+1, end));
}

int query(int node, int start, int end, int left, int right) {
    if (right < start || end < left) return 0;
    if (left <= start && end <= right) return tree[node];

    return max(query(node*2, start, (start+end)/2, left, right),
                query(node*2+1, (start+end)/2+1, end, left, right));
}

int main(void) {
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; ++i)
        scanf("%d", arr+i);
    init(1, 0, n-1);

    for (int i = m-1; i <= n-m; ++i)
        printf("%d ", query(1, 0, n-1, i-m+1, i+m-1));

    return 0;
}
