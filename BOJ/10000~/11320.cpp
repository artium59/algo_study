#include <iostream>

int main() {
    int t, a, b;

    scanf("%d", &t);
    while(t--) {
        scanf("%d %d", &a, &b);
        printf("%d\n", (a*a)/(b*b));
    }

    return 0;
}
