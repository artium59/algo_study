#include <cstdio>

int tc, n, arr[100000], brr[100000];
long long ans;

void merge(int start, int end) {
    int s1=start, e1=(start+end)/2, s2=(start+end)/2+1, e2=end;
    int loc=0;

    while (s1 <= e1 && s2 <= e2) {
        if (arr[s1] < arr[s2])
            brr[loc++] = arr[s1++];
        else {
            brr[loc++] = arr[s2++];
            ans += e1-s1+1;
        }
    }

    while (s1 <= e1)
        brr[loc++] = arr[s1++];

    while (s2 <= e2)
        brr[loc++] = arr[s2++];

    for (int i = 0; i < loc; ++i)
        arr[start++] = brr[i];
}

void divide(int start, int end) {
    if (start >= end) return;

    divide(start, (start+end)/2);
    divide((start+end)/2+1, end);

    merge(start, end);
}

int main() {
    scanf("%d", &tc);
    while (tc--) {
        scanf("%d", &n);
        for (int i = 0; i < n; ++i)
            scanf("%d", arr+i);

        ans = 0;
        divide(0, n-1);

        printf("%lld\n", ans);
    }

    return 0;
}
