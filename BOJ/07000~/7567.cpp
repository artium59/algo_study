#include <iostream>

int main() {
    int ans = 0;
    char ch, before;

    while (scanf(" %c", &ch) != EOF) {
        if (ans == 0) {
            ans += 10;
            before = ch;
        }
        else {
            ans += 5;

            if (before != ch) {
                ans += 5;
                before = ch;
            }
        }
    }

    printf("%d", ans);

    return 0;
}
