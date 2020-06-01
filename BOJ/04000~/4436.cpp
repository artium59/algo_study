#include <cstdio>

int cnt;
long long n;
bool check[10];

void calc(long long num) {
    while (num > 0) {
        if (!check[num % 10]) {
            check[num % 10] = true;
            ++cnt;
        }
        num /= 10;
    }
}

int main() {
    while (scanf("%lld", &n) != EOF) {
        cnt = 0;
        for (int i = 0; i < 10; ++i)
            check[i] = false;

        for (int k = 1; ; ++k) {
            calc(n * k);

            if (cnt == 10) {
                printf("%d\n", k);
                break;
            }
        }
    }

    return 0;
}
