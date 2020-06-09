#include <cstdio>

int n, last, cow[100000], tree[262144];

void update(int node, int start, int end, int loc) {
    if (end < loc || loc < start) return;
    ++tree[node];
    if (start >= end) return;

    update(node*2, start, (start+end)/2, loc);
    update(node*2+1, (start+end)/2+1, end, loc);
}

int query(int node, int start, int end, int loc) {
    if (loc < start) return 0;
    if (end <= loc) return tree[node];
    
    return query(node*2, start, (start+end)/2, loc) +
            query(node*2+1, (start+end)/2+1, end, loc);
}

int main(void) {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", cow+i);
        --cow[i];
    }

    for (last = n-1; last > 0; --last) {
        update(1, 0, n-1, cow[last]);
        if (cow[last-1] > cow[last]) break;
    }

    printf("%d\n", last);
    for (int i = 0; i < last; ++i) {
        printf("%d ", query(1, 0, n-1, cow[i]-1)+last-i-1);
        update(1, 0, n-1, cow[i]);
    }

    return 0;
}
