#include <cstdio>
#include <unordered_set>
using ll = long long;

const ll prime[2] { 1000000007LL, 1000000321LL }, mul=31LL, key_mul = 1000000009LL;
int size, l, r, m;
char str[200000];
std::unordered_set<ll> myset;

bool find(int k) {
    myset.clear();

    ll ret1=0, ret2=0, del1=1, del2=1, key;

    for (int i = 0; i < k; ++i) {
        ret1 = (ret1*mul + str[i]-'a') % prime[0];
        ret2 = (ret2*mul + str[i]-'a') % prime[1];

        if (i < k-1) {
            del1 = (del1 * mul) % prime[0];
            del2 = (del2 * mul) % prime[1];
        }
    }
    key = ret1 * key_mul + ret2;
    myset.insert(key);

    for (int i = k; i < size; ++i) {
        ret1 = (ret1 - ((str[i-k]-'a')*del1)%prime[0]) % prime[0];
        ret2 = (ret2 - ((str[i-k]-'a')*del2)%prime[1]) % prime[1];

        ret1 = (ret1 * mul + str[i]-'a') % prime[0];
        ret2 = (ret2 * mul + str[i]-'a') % prime[1];

        key = ret1 * key_mul + ret2;

        if (myset.find(key) != myset.end()) return true;
        myset.insert(key);
    }

    return false;
}

int main() {
    scanf("%d", &size);
    for (int i = 0; i < size; ++i) scanf(" %c", str+i);

    r = size-1;
    while (l <= r) {
        m = (l + r) / 2;

        if (find(m)) l = m+1;
        else r = m-1;
    }

    printf("%d", r);

    return 0;
}
