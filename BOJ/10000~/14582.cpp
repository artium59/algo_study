#include <iostream>

int main() {
    int a[9], b[9], asum = 0, bsum = 0;
    bool isYes = true;

    for (int i = 0; i < 9; i++)
        scanf("%d", &a[i]);

    for (int i = 0; i < 9; i++)
        scanf("%d", &b[i]);

    for (int i = 0; i < 9; i++) {
        asum += a[i];
        if (a > 0 && asum > bsum) break;
        bsum += b[i];
        if (i == 8) isYes = false;
    }

    printf(isYes ? "Yes" : "No");

    return 0;
}
