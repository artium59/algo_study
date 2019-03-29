#include <iostream>

int cards[1000];

int max(int a, int b) {
    return a > b ? a : b;
}

int main() {
    int n;

    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &cards[i]);

        for (int j = 0; j < i; j++) {
            if (j > i-j-1) break;
            cards[i] = max(cards[i], cards[j] + cards[i-j-1]);
        }
    }

    printf("%d", cards[n-1]);

    return 0;
}
