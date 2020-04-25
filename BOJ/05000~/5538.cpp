#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int cnt = 0, ans = 0;
    char ch = 'A';
    string str;
    vector<pair<char, int>> vec;

    cin >> str;
    for (const auto& s : str) {
        if (ch == s)
            ++cnt;
        else {
            vec.push_back({ ch, cnt });
            ch = s; cnt = 1;
        }
    }
    vec.push_back({ ch, cnt });

    for (int i = 0; i <= vec.size()-3 && vec.size() > 2; ++i) {
        if (vec[i].first == 'J' && vec[i+1].first == 'O' && vec[i+2].first == 'I') {
            if (vec[i+1].second <= vec[i].second && vec[i+1].second <= vec[i+2].second)
                ans = max(ans, vec[i+1].second);
        }
    }

    cout << ans;
    return 0;
}
