#include <iostream>

const int MAX = 1000000;
int a[MAX], b[MAX], n, m, l = 0, r = 0;

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    for (int i = 0; i < m; i++)
        scanf("%d", &b[i]);

    while (l < n && r < m) {
        if (a[l] < b[r]) {
            printf("%d ", a[l]); l++;
        }
        else {
            printf("%d ", b[r]); r++;
        }
    }

    for (int i = l; i < n; i++)
        printf("%d ", a[i]);

    for (int i = r; i < m; i++)
        printf("%d ", b[i]);

    return 0;
}
