#include <iostream>
#include <unordered_set>
using namespace std;
using ll = long long;

const ll primes[2] = { 1234567891LL, 1000000007LL };
const ll mul = 31LL, key_mul = 1000000321LL;
int needle_checker[26], haystack_checker[26];
ll hash_array[200000];
string n, h;
unordered_set<ll> needles;

bool is_equal() {
    for (int a = 0; a < 26; a++) {
        if (needle_checker[a] != haystack_checker[a])
            return false;
    }
    return true;
}

void make_hash() {
    ll ret1=0, ret2=0, del1=1, del2=1, key;

    for (int i = 0; i < n.size(); i++) {
        ret1 = (ret1*mul + h[i]) % primes[0];
        ret2 = (ret2*mul + h[i]) % primes[1];

        if (i < n.size()-1) {
            del1 = (del1 * mul) % primes[0];
            del2 = (del2 * mul) % primes[1];
        }
    }
    key = ret1 * key_mul + ret2;
    hash_array[n.size()-1] = key;

    for (int i = n.size(); i < h.size(); i++) {
        ret1 = ((ret1 - (h[i-n.size()]*del1)%primes[0]) + primes[0]) % primes[0];
        ret2 = ((ret2 - (h[i-n.size()]*del2)%primes[1]) + primes[1]) % primes[1];

        ret1 = (ret1*mul + h[i]) % primes[0];
        ret2 = (ret2*mul + h[i]) % primes[1];

        key = ret1 * key_mul + ret2;
        hash_array[i] = key;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> h;

    if (n.size() > h.size()) {
        printf("0");
        return 0;
    }

    make_hash();
    for (int i = 0; i < n.size(); i++)
        needle_checker[n[i]-'a']++;

    for (int i = 0; i < h.size(); i++) {
        haystack_checker[h[i]-'a']++;
        if (i >= n.size())
            haystack_checker[h[i-n.size()]-'a']--;

        if (is_equal()) needles.insert(hash_array[i]);
    }

    printf("%lld", needles.size());
    return 0;
}
