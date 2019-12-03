#include <cstdio>

const int MAX=100000;
int n, m, a, b, arr[MAX], min_tree[MAX*3], max_tree[MAX*3];

inline int max(int a, int b) { return a > b ? a : b; }
inline int min(int a, int b) { return a < b ? a : b; }

int init(int node, int start, int end, bool is_find_min) {
    if (start >= end) {
        if (is_find_min) return min_tree[node] = arr[start];
        else return max_tree[node] = arr[start];
    }

    if (is_find_min)
        return min_tree[node] = min(init(node*2, start, (start+end)/2, is_find_min),
                                    init(node*2+1, (start+end)/2+1, end, is_find_min));
    else
        return max_tree[node] = max(init(node*2, start, (start+end)/2, is_find_min),
                                    init(node*2+1, (start+end)/2+1, end, is_find_min));
}

int search(int node, int start, int end, int left, int right, bool is_find_min) {
    if (right < start || end < left) return is_find_min ? 1e9+9 : 0;

    if (left <= start && end <= right)
        return is_find_min ? min_tree[node] : max_tree[node];

    if (is_find_min)
        return min(search(node*2, start, (start+end)/2, left, right, is_find_min),
                    search(node*2+1, (start+end)/2+1, end, left, right, is_find_min));
    else
        return max(search(node*2, start, (start+end)/2, left, right, is_find_min),
                    search(node*2+1, (start+end)/2+1, end, left, right, is_find_min));
}

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; ++i) scanf("%d", arr+i);
    init(1, 0, n-1, true); init(1, 0, n-1, false);

    while (m--) {
        scanf("%d %d", &a, &b); --a; --b;
        printf("%d %d\n",
            search(1, 0, n-1, a, b, true), search(1, 0, n-1, a, b, false));
    }

    return 0;
}
