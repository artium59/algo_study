#include <iostream>
#include <unordered_set>
using namespace std;
using ll = long long;

const ll primes[] { 1000000009LL, 1234567891LL };
const ll mul = 41LL, key_mul = 1000000321LL;
string str1, str2;
unordered_set<ll> myset;

int rabin_karp(string& s, int len, bool is_find) {
    ll ret1=0, ret2=0, del1=1, del2=1, key;

    for (int i = 0; i < len; ++i) {
        ret1 = (ret1*mul + s[i]) % primes[0];
        ret2 = (ret2*mul + s[i]) % primes[1];

        if (i < len-1) {
            del1 = (del1 * mul) % primes[0];
            del2 = (del2 * mul) % primes[1];
        }
    }
    key = ret1 * key_mul + ret2;
    if (myset.find(key) != myset.end() && is_find) return len-1;
    if (!is_find) myset.insert(key);

    for (int i = len; i < s.size(); ++i) {
        ret1 = ((ret1 - (s[i-len]*del1)%primes[0]) + primes[0]) % primes[0];
        ret2 = ((ret2 - (s[i-len]*del2)%primes[1]) + primes[1]) % primes[1];

        ret1 = (ret1*mul + s[i]) % primes[0];
        ret2 = (ret2*mul + s[i]) % primes[1];

        key = ret1 * key_mul + ret2;
        if (myset.find(key) != myset.end() && is_find) return i;
        if (!is_find) myset.insert(key);
    }

    return -1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> str1 >> str2;

    int l = 0, r = str1.size();
    while (l+1 != r) {
        int m = (l + r) / 2;

        myset.clear();
        rabin_karp(str1, m, false);

        if (rabin_karp(str2, m, true) == -1) r = m;
        else l = m;
    }

    cout << l << '\n';
    rabin_karp(str1, l, false);
    r = rabin_karp(str2, l, true);
    for (int i = r-l+1; i <= r; ++i)
        cout << str2[i];

    return 0;
}
