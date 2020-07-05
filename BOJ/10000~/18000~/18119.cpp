#include <iostream>
#include <algorithm>
using namespace std;

int n, m, o, tmp, loc, ans, words[10000], forget_cnt[10000];
char x;
string str;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        cin >> str;

        sort(str.begin(), str.end());
        loc = unique(str.begin(), str.end()) - str.begin();

        for (int j = 0; j < loc; ++j)
            words[i] |= 1 << (str[j]-'a');
    }
    sort(words, words+n); ans = n;

    while (m--) {
        cin >> o >> x;

        tmp = 1 << (x-'a');
        loc = lower_bound(words, words+n, tmp) - words;

        if (o == 1) {
            while (loc < n) {
                if ((tmp & words[loc])) {
                    ++forget_cnt[loc];
                    if (forget_cnt[loc] == 1) --ans;
                }

                ++loc;
            }
        }
        else {
            while (loc < n) {
                if ((tmp & words[loc])) {
                    --forget_cnt[loc];
                    if (forget_cnt[loc] == 0) ++ans;
                }

                ++loc;
            }
        }

        cout << ans << '\n';
    }

    return 0;
}
