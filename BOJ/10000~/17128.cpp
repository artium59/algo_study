#include <iostream>

const int MAX = 200000;
int n, q, t, start, ans = 0, arr[MAX], s[MAX];

int main() {
    scanf("%d %d", &n, &q);
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    for (int i = 0; i < n; i++) {
        s[i] = arr[i]*arr[(i+1)%n]*arr[(i+2)%n]*arr[(i+3)%n];
        ans += s[i];
    }

    for (int i = 0; i < q; i++) {
        scanf("%d", &t);

        start = (t-4+n)%n;
        for (int j = 0 ; j < 4; j++) {
            s[start] *= -1;
            ans += 2*s[start];
            start = (start+1) % n;
        }

        printf("%d\n", ans);
    }

    return 0;
}
