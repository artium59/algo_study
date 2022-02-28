#include <cstdio>

int n, m, q, a, b, arr[200000], brr[200000], min_tree[524288], max_tree[524288];

inline int min(int x, int y) { return x < y ? x : y; }
inline int max(int x, int y) { return x > y ? x : y; }

inline void swap(int loc_x, int loc_y) {
    int temp = arr[loc_x];
    arr[loc_x] = arr[loc_y];
    arr[loc_y] = temp;

    temp = brr[arr[loc_x]-1];
    brr[arr[loc_x]-1] = brr[arr[loc_y]-1];
    brr[arr[loc_y]-1] = temp;
}

int min_init(int node, int start, int end) {
    if (start >= end)
        return min_tree[node] = brr[start];

    return min_tree[node] = min(min_init(node*2, start, (start+end)/2),
                                min_init(node*2+1, (start+end)/2+1, end));
}

int max_init(int node, int start, int end) {
    if (start >= end)
        return max_tree[node] = brr[start];

    return max_tree[node] = max(max_init(node*2, start, (start+end)/2),
                                max_init(node*2+1, (start+end)/2+1, end));
}

int min_update(int node, int start, int end, int loc) {
    if (loc < start || end < loc) return min_tree[node];
    if (start >= end) return min_tree[node] = brr[loc]; 

    return min_tree[node] = min(min_update(node*2, start, (start+end)/2, loc),
                                min_update(node*2+1, (start+end)/2+1, end, loc));
}

int max_update(int node, int start, int end, int loc) {
    if (loc < start || end < loc) return max_tree[node];
    if (start >= end) return max_tree[node] = brr[loc];

    return max_tree[node] = max(max_update(node*2, start, (start+end)/2, loc),
                                max_update(node*2+1, (start+end)/2+1, end, loc));
}

int min_query(int node, int start, int end, int left, int right) {
    if (right < start || end < left) return 1e9;
    if (left <= start && end <= right) return min_tree[node];

    return min(min_query(node*2, start, (start+end)/2, left, right),
               min_query(node*2+1, (start+end)/2+1, end, left, right));
}

int max_query(int node, int start, int end, int left, int right) {
    if (right < start || end < left) return -1e9;
    if (left <= start && end <= right) return max_tree[node];

    return max(max_query(node*2, start, (start+end)/2, left, right),
               max_query(node*2+1, (start+end)/2+1, end, left, right));
}

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%d", arr+i);
        brr[arr[i]-1] = i;
    }

    min_init(1, 0, n-1);
    max_init(1, 0, n-1);

    while (m--) {
        scanf("%d %d %d", &q, &a, &b); --a; --b;
        if (q == 1) {
            swap(a, b);

            min_update(1, 0, n-1, arr[a]-1);
            max_update(1, 0, n-1, arr[a]-1);

            min_update(1, 0, n-1, arr[b]-1);
            max_update(1, 0, n-1, arr[b]-1);
        }
        else {
            q = max_query(1, 0, n-1, a, b) - min_query(1, 0, n-1, a, b);
            printf(b-a == q ? "YES\n" : "NO\n");
        }
    }

    return 0;
}
