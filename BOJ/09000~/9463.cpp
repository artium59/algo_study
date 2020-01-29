#include <cstdio>

int tc, n, t, trans[100001], arr[100001];
long long ans;

long long merge(int s, int m, int e) {
    int s1=s, e1=m, s2=m+1, e2=e, idx=0;
    long long ret=0;

    while (s1 <= e1 && s2 <= e2) {
        if (arr[s1] < arr[s2])
            trans[idx] = arr[s1], ++s1;
        else
            trans[idx] = arr[s2], ++s2, ret += e1-s1+1;
        ++idx;
    }

    while (s1 <= e1) {
        trans[idx] = arr[s1]; ++s1; ++idx;
    }

    while (s2 <= e2) {
        trans[idx] = arr[s2]; ++s2; ++idx;
    }

    for (s1 = s; s1 <= e; ++s1)
        arr[s1] = trans[s1-s];

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
    scanf("%d", &tc);
    while (tc--) {
        ans = 0;
        scanf("%d", &n);
        for (int i = 0; i < n; ++i) {
            scanf("%d", &t);
            trans[t] = i;
        }
        for (int i = 0; i < n; ++i) {
            scanf("%d", &t);
            arr[i] = trans[t];
        }

        divide(0, n-1);
        printf("%lld\n", ans);
    }

    return 0;
}
