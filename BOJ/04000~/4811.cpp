#include <iostream>
#include <cstring>

long long cache[31][31];

long long Count(int w, int h) {
    if (w > h) return 0;

    if (w == 0) return 1;

    long long& ret = cache[w][h];
    if (ret != -1) return ret;

    ret = Count(w-1, h) + Count(w, h-1);

    return ret;
}

int main() {
    int n;

    memset(cache, -1, sizeof(cache));

    while (true) {
        scanf("%d", &n);

        if (n == 0) break;

        printf("%lld\n", Count(n, n));
    }

    return 0;
}
