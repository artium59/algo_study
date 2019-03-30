#include <iostream>

int main() {
    int t, n, ans, cur, dice[6];

    scanf("%d", &t);
    for (int h = 0; h < t; h++) {
        ans = 0; cur = 0;
        scanf("%d", &n);
        for (int i = 0; i < 6; i++)
            scanf("%d", &dice[i]);

        while (cur < n) {
            for (int i = 0; i < 6; i++) {
                if (cur + dice[i] <= n) {
                    cur += dice[i]; ans += cur;
                }
            }
        }

        printf("%d\n", ans);
    }

    return 0;
}
