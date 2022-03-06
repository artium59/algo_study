#include <cstdio>

const int MAX = 500000;
int n, arr[MAX], tree[1048576];
long long ans;

inline int min(int a, int b) { return a < b ? a : b; }

long long merge(int s, int m, int e) {
    int s1=s, e1=m, s2=m+1, e2=e, idx=0;
    long long ret=0;

    while (s1 <= e1 && s2 <= e2) {
        if (arr[s1] <= arr[s2])
            tree[idx] = arr[s1], ++s1;
        else
            tree[idx] = arr[s2], ++s2, ret += e1-s1+1;
        ++idx;
    }

    while (s1 <= e1) {
        tree[idx] = arr[s1]; ++s1; ++idx;
    }

    while (s2 <= e2) {
        tree[idx] = arr[s2]; ++s2; ++idx;
    }

    for (s1 = s; s1 <= e; ++s1)
        arr[s1] = tree[s1-s];

    return ret;
}

void divide(int start, int end) {
    if (start >= end) return;
    int mid = (start+end)/2;

    divide(start, mid);
    divide(mid+1, end);

    ans += merge(start, mid, end);
}

int main() {
    scanf("%d", &n); 
    for (int i = 0; i < n; i++)
        scanf("%d", arr+i);

    divide(0, n-1);
    printf("%lld", ans);
    return 0;
}
