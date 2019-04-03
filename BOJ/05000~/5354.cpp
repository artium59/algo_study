#include <iostream>

int main() {
    int t, n;

    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0 || j == 0 || i == n-1 || j == n-1) printf("#");
                else printf("J");
            }
            printf("\n");
        }
        if (t != 0) printf("\n");
    }

    return 0;
}
