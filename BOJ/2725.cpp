#include <iostream>

int arr[1001];

int gcd(int a, int b) {
    if (b == 0) return a;
    else return gcd(b, a%b);
}

void Init() {
    for (int i = 0; i < 1001; i++)
        arr[i] = 0;
}

int main() {
    int c, t;

    Init();
    for (int i = 2; i < 1001; i++) {
        for (int j = 1; j < i; j++) {
            if (gcd(i, j) == 1) arr[i]++;
        }
    }

    for (int i = 3; i < 1001; i++)
        arr[i] += arr[i-1];

    scanf("%d", &c);
    for (int i = 0; i < c; i++) {
        scanf("%d", &t);
        printf("%d\n", 2*arr[t] + 3);
    }

    return 0;
}
