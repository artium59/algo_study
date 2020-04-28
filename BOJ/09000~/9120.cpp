#include <iostream>
using namespace std;
using ll = long long;

const ll prime[2] = { 1234567891LL, 1000000321LL };
const ll mul = 31LL, key_mul = 1000000007LL;
ll ret0, ret1, del0, del1, key;
int tc, cnt;
string w, t;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> tc;
    while (tc--) {
        cnt = 0;
        ret0 = ret1 = 0;
        del0 = del1 = 1;

        cin >> w >> t;
        if (w.size() > t.size()) {
            cout << "0\n";
            continue;
        }

        for (int i = 0; i < w.size(); ++i) {
            ret0 = (ret0 * mul + w[i]-'A') % prime[0];
            ret1 = (ret1 * mul + w[i]-'A') % prime[1];

            if (i > 0) {
                del0 = (del0 * mul) % prime[0];
                del1 = (del1 * mul) % prime[1];
            }
        }
        key = ret0 * key_mul + ret1;

        ret0 = ret1= 0;
        for (int i = 0; i < t.size(); ++i) {
            if (i >= w.size()) {
                ret0 = ((ret0 - (t[i-w.size()]-'A')*del0)%prime[0] + prime[0]) % prime[0];
                ret1 = ((ret1 - (t[i-w.size()]-'A')*del1)%prime[1] + prime[1]) % prime[1];
            }

            ret0 = (ret0 * mul + t[i]-'A') % prime[0];
            ret1 = (ret1 * mul + t[i]-'A') % prime[1];

            if (i < w.size()-1) continue;
            if (key == ret0 * key_mul + ret1) ++cnt;
        }

        cout << cnt << '\n';
    }

    return 0;
}
