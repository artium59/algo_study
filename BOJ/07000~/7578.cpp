#include <cstdio>

int n, t, arr[500000], tree[1048577];
long long ans;

long long merging(int start, int end) {
    int s1=start, e1=(start+end)/2, s2=(start+end)/2+1, e2=end, loc=0;
    long long ret=0;

    while (s1 <= e1 && s2 <= e2) {
        if (arr[s1] < arr[s2]) tree[loc] = arr[s1], ++s1;
        else tree[loc] = arr[s2], ++s2, ret += e1-s1+1;
        ++loc;
    }

    for ( ; s1 <= e1; ++loc)
        tree[loc] = arr[s1], ++s1;

    for ( ; s2 <= e2; ++loc)
        tree[loc] = arr[s2], ++s2;

    for (int i = start; i <= end; ++i)
        arr[i] = tree[i - start];

    return ret;
}

void mergesort(int start, int end) {
    if (start >= end) return;

    mergesort(start, (start+end)/2);
    mergesort((start+end)/2+1, end);

    ans += merging(start, end);
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &t);
        tree[t] = i;
    }
    for (int i = 0; i < n; ++i) {
        scanf("%d", &t);
        arr[i] = tree[t];
    }

    mergesort(0, n-1);

    printf("%lld", ans);

    return 0;
}
