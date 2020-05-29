#include <iostream>
#include <functional>
#include <map>
using namespace std;
using ll = long long;

const ll primes[] { 1000000009LL, 1234567891LL };
const ll mul = 10000099LL, key_mul = 1000000321LL;
ll ret0, ret1, del0, del1;
int n, k, arr[20000];
map<ll, int> mymap;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    function<bool(int)> rabinkarp = [](int length) {
        mymap.clear();

        ret0 = ret1 = 0;
        del0 = del1 = 1;
        for (int i = 0; i < length; ++i) {
            ret0 = (ret0*mul + (ll)arr[i]) % primes[0];
            ret1 = (ret1*mul + (ll)arr[i]) % primes[1];

            if (i > 0) {
                del0 = (del0 * mul) % primes[0];
                del1 = (del1 * mul) % primes[1];
            }
        }
        mymap.insert({ ret0*key_mul + ret1, 1 });

        for (int i = length; i < n; ++i) {
            ret0 = (ret0 - (del0*(ll)arr[i-length])%primes[0] + primes[0]) % primes[0];
            ret1 = (ret1 - (del1*(ll)arr[i-length])%primes[1] + primes[1]) % primes[1];
            ret0 = (ret0*mul + (ll)arr[i]) % primes[0];
            ret1 = (ret1*mul + (ll)arr[i]) % primes[1];

            if (mymap.find(ret0*key_mul + ret1) != mymap.end()) {
                if (++mymap[ret0*key_mul + ret1] >= k)
                    return true;
            }
            else
                mymap.insert({ ret0*key_mul + ret1, 1 });
        }

        return false;
    };

    cin >> n >> k;
    for (int i = 0; i < n; ++i)
        cin >> arr[i];

    int l = 0, r = n, m;
    while (l <= r) {
        m = (l + r) / 2;

        if (rabinkarp(m)) l = m+1;
        else r = m-1;
    }

    cout << r;
    return 0;
}
