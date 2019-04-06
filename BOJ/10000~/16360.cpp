#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

char ch[8] = {'i', 'y', 'n', 'r', 't', 'v', 'w', 'l'};
string s, ans;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    vector<string> vec;

    cin >> n;
    while (n--) {
        cin >> s;
        vec.push_back(s);
    }

    for_each(vec.begin(), vec.end(), [](const auto& v) {
        ans = v;

        for (int i = 0; i < 8; i++) {
            if (ans.back() == ch[i]) {
                if (i == 0) ans += 'o';
                else if (i == 1) {
                    ans.pop_back();
                    ans += "io";
                }
                else if (i == 2) {
                    ans.pop_back();
                    ans += "ane";
                }
                else if (i == 3) ans += 'e';
                else if (i == 4) ans += 'a';
                else if (i == 5) ans += 'e';
                else if (i == 6) ans += 'a';
                else ans += 'e';

                break;
            }
			
            if (ans.back() == 'e') {
                ans.pop_back();
                if (ans.back() == 'n') {
                    ans.pop_back();
                    ans += "ane";
                    break;
                }
                ans += "eu";
                break;
            }

            if (i == 7 && ans.back() != 'u' &&
                ans.back() != 'a' && ans.back() != 'o') ans += 'u';
        }

        ans += 's';
        cout << ans << "\n";
    });

    return 0;
}
