#include <iostream>

inline int max(int a, int b) { return a > b ? a : b; }

int main() {
    int d, n, m, t, x, y, ans;
    bool swch;

    scanf("%d", &d);
    while (d--) {
        x = y = 0; ans = 0; swch = false;

        scanf("%d %d", &n, &m);
        for (int i = 0; i < n; i++) {
            scanf("%d", &t);

            if (t < m) {
                if (swch) ans = max(ans, x);
                swch = false;
                x = y = 0;
            }
            else if (t > m) {
                x += t;
                if (swch) y += t;
            }
            else {
                if (swch) {
                    ans = max(ans, x);
                    x = y + t;
                }
                else x += t;

                swch = true;
                y = 0;
            }
        }

        if (swch) ans = max(ans, x);
        printf("%d\n", ans);
    }

    return 0;
}
