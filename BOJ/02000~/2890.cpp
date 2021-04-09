#include <iostream>
#include <set>
using namespace std;

int r, c, ans[10];
string kajak;
set<int> myset;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> r >> c;
    for (int i = 0; i < r; ++i) {
        cin >> kajak;
        for (int j = c-2; j > 0; --j) {
            if (kajak[j] == '.') continue;
            ans[kajak[j]-'0'] = j;
            myset.insert(j);
            break;
        }
    }

    for (int i = 1; i < 10; ++i) {
        c = 0;
        for (auto it = myset.begin(); it != myset.end(); ++it) {
            if (ans[i] == *it) {
                cout << myset.size()-c << '\n';
                break;
            }
            ++c;
        }
    }

    return 0;
}
