#include <cstdio>

inline int min(int a, int b) { return a < b ? a : b; }

int n, m, l, r, arr[100000], tree[400000];

int init(int node, int start, int end) {
    if (start >= end)
        return tree[node] = arr[start];
    else
        return tree[node] = min(init(node*2, start, (start+end)/2), init(node*2+1, (start+end)/2+1, end));
}

int search(int node, int start, int end, int left, int right) {
    if (right < start || end < left) return 1e9;

    if (left <= start && end <= right) return tree[node];

    return min(search(node*2, start, (start+end)/2, left, right),
                search(node*2+1, (start+end)/2+1, end, left, right));
}

int main() {
    scanf("%d %d", &m, &n);
    for (int i = 0 ; i < m; ++i)
        scanf("%d", arr+i);
    init(1, 0, m-1);

    while (n--) {
        scanf("%d %d", &l, &r);
        printf("%d\n", search(1, 0, m-1, l-1, r-1));
    }

    return 0;
}
