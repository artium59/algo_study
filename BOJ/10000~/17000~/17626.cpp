#include <cstdio>
#include <algorithm>

int n, twice[225], dp[50001];

int find(int a) {
    if (a == 0) return 0;

    int& ret = dp[a];
    if (ret != 0) return ret;
    ret = 10;

    int loc = std::lower_bound(twice, twice+225, a) - twice;

    for ( ; loc > 0; loc--) {
        if (a - twice[loc] >= 0)
            ret = std::min(ret, find(a-twice[loc])+1);
    }

    return ret;
}

int main() {
    for (int i = 1; i < 225; i++) {
        twice[i] = i*i;
        if (i*i < 50001) dp[i*i] = 1;
    }

    scanf("%d", &n);
    printf("%d", find(n));

    return 0;
}
