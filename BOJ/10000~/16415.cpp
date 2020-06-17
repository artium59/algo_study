#include <iostream>
#include <unordered_set>
using namespace std;
using ll = long long;

const ll primes[2] { 1234567891LL, 1000000321LL };
const ll key_mul = 1000000007LL, mul = 31LL;
ll ret1, ret2, del1, del2, key;
int l, m, r;
string str, tmp, ans;
unordered_set<ll> us;

bool find(int k, bool check) {
    bool ret = false;
    us.clear();

    ret1 = ret2 = 0;
    del1 = del2 = 1;
    for (int i = 0; i < k; ++i) {
        ret1 = (ret1*mul + str[i]) % primes[0];
        ret2 = (ret2*mul + str[i]) % primes[1];

        if (i > 0) {
            del1 = (del1 * mul) % primes[0];
            del2 = (del2 * mul) % primes[1];
        }
    }
    key = ret1*key_mul + ret2;
    us.insert(key);

    for (int i = k; i < str.size(); ++i) {
        ret1 = ((ret1-(str[i-k]*del1)%primes[0]) + primes[0]) % primes[0];
        ret2 = ((ret2-(str[i-k]*del2)%primes[1]) + primes[1]) % primes[1];
        ret1 = (ret1*mul + str[i]) % primes[0];
        ret2 = (ret2*mul + str[i]) % primes[1];

        key = ret1*key_mul + ret2;
        if (us.find(key) != us.end()) {
            ret = true;
            if (!check) break;

            tmp = str.substr(i-k+1, k);

            if (ans.size() < tmp.size())
                ans = tmp;
            else if (ans.size() == tmp.size()) {
                for (int z = 0; z < ans.size(); ++z) {
                    if (ans[z] != tmp[z]) {
                        if (ans[z] > tmp[z]) ans = tmp;
                        break;
                    }
                }
            }
        }
        else
            us.insert(key);
    }

    return ret;
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> str;

    r = str.size();
    while (l+1 != r) {
        m = (l+r) / 2;
        if (find(m, false)) l = m;
        else r = m;
    }
    find(l, true);

    cout << ans;
    return 0;
}
