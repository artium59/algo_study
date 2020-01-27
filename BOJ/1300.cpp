#include <cstdio>

inline int min(int a, int b) { return a < b ? a: b; }

int main() {
    int n, k, left=0, mid, right, cnt;
    scanf("%d %d", &n, &k);

    right = k;
    while (left <= right) {
        mid = (left+right) / 2; cnt=0;

        for (int i = 1; i <= n; ++i) {
            cnt += min(mid/i, n);
            if (cnt > k) break;
        }

        if (cnt >= k) right = mid-1;
        else left = mid+1;
    }
    printf("%d", left);

    return 0;
}
