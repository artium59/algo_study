#include <iostream>
using namespace std;

int calc(int need, int have) {
    int before = 0, after= 0;

    while (have / need > 0) {
        after += have / need;
        have %= need;
        have += (after - before) * 2;
        before = after;
    }

    return after;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, k, sum = 0, max = 0;
    string str, ans;

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> str >> k >> m;

        k = calc(k, m);
        sum += k;
        if (k > max) {
            max = k; ans = str;
        }
    }

    cout << sum << "\n" << ans;

    return 0;
}
