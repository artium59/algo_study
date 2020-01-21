#include <cstdio>

const int M = 1234567891;
int l;
long long ans, arr[50] = { 1 };
char ch;

int main() {
    for (int i = 1; i < 50; ++i)
        arr[i] = (arr[i-1] * 31) % M;

    scanf("%d", &l);
    for (int i = 0; i < l; ++i) {
        scanf(" %c", &ch);
        ans += ((ch - 'a' + 1) * arr[i]) % M;
        ans %= M;
    }

    printf("%lld", ans);

    return 0;
}
