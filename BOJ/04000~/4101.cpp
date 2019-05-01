#include <iostream>

int main() {
    int a, b;

    while (true) {
        scanf("%d %d", &a, &b);
        if (a == 0 && b == 0) break;
        printf(a > b ? "Yes\n" : "No\n");
    }

    return 0;
}
