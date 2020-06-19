#include <cstdio>

int n, q, a, b, cow[50000], min_tree[131072], max_tree[131072];

inline int min(int a, int b) { return a < b ? a : b; }
inline int max(int a, int b) { return a > b ? a : b; }

int init(int node, int start, int end, bool is_min) {
    if (start >= end) {
        if (is_min) return min_tree[node] = cow[start];
        else return max_tree[node] = cow[start];
    }

    if (is_min) return min_tree[node] = min(init(node*2, start, (start+end)/2, is_min),
                                            init(node*2+1, (start+end)/2+1, end, is_min));
    else return max_tree[node] = max(init(node*2, start, (start+end)/2, is_min),
                                    init(node*2+1, (start+end)/2+1, end, is_min));
}

int query(int node, int start, int end, int left, int right, bool is_min) {
    if (end < left || right < start) return is_min ? 1e9 : -1e9;
    if (left <= start && end <= right) return is_min ? min_tree[node] : max_tree[node];

    if (is_min) return min(query(node*2, start, (start+end)/2, left, right, is_min),
                            query(node*2+1, (start+end)/2+1, end, left, right, is_min));
    else return max(query(node*2, start, (start+end)/2, left, right, is_min),
                    query(node*2+1, (start+end)/2+1, end, left, right, is_min));
}

int main(void) {
    scanf("%d %d", &n, &q);
    for (int i = 0; i < n; ++i)
        scanf("%d", cow+i);
    
    init(1, 0, n-1, true);
    init(1, 0, n-1, false);
    for (int i = 0; i < q; ++i) {
        scanf("%d %d", &a, &b);
        printf("%d\n", query(1, 0, n-1, a-1, b-1, false)-query(1, 0, n-1, a-1, b-1, true));
    }

    return 0;
}
