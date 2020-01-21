// https://chogahui05.blog.me/221500107112

#include <cstdio>
#include <unordered_set>
using ll = long long;

const ll prime[2] { 1234567891LL, 1000000009LL }, key_mul = 1000000007LL;
const int MUL = 31;
int l, r, m, size;
char str[200000];
std::unordered_set<ll> myset;

bool find(int k) {
    myset.clear();
    ll ret1=0, ret2=0, del1=1, del2=1, key;

    for (int i = 0; i < k; ++i) {
        ret1 = (ret1*MUL + str[i]-'a') % prime[0];
        ret2 = (ret2*MUL + str[i]-'a') % prime[1];

        if (i < k-1) {
            del1 = (del1 * MUL) % prime[0];
            del2 = (del2 * MUL) % prime[1];
        }
    }
    key = ret1 * key_mul + ret2;
    myset.insert(key);

    for (int i = k; i < size; ++i) {
        ret1 = ((ret1-((str[i-k]-'a')*del1)%prime[0]) + prime[0]) % prime[0];
        ret2 = ((ret2-((str[i-k]-'a')*del2)%prime[1]) + prime[1]) % prime[1];
        ret1 = (ret1*MUL + str[i]-'a') % prime[0];
        ret2 = (ret2*MUL + str[i]-'a') % prime[1];

        key = ret1 * key_mul + ret2;
        if (myset.find(key) != myset.end()) return true;
        myset.insert(key);
    }

    return false;
}

int main() {
    scanf("%d", &size);
    for (int i = 0; i < size; ++i) scanf(" %c", str+i);

    r = size;
    while (l <= r) {
        m = (l + r) / 2;

        if (find(m)) l = m+1;
        else r = m-1;
    }

    printf("%d", r);

    return 0;
}
