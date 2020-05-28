#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    function<bool(string, string)> bigger = [](const auto& a, const auto& b) {
        if (a == "" || b == "") return false;

        for (int i = 0; i < min(a.size(), b.size()); ++i) {
            if (a[i] != b[i]) return a[i] < b[i];
        }
        return a.size() < b.size();
    };

    int n;
    string str, ans;

    while (true) {
        cin >> n;
        if (n == 0) break;

        vector<string> vec;
        for (int i = 0; i < n; ++i) {
            cin >> str;
            vec.push_back(str);
        }

        sort(vec.begin(), vec.end(), bigger);

        n /= 2;
        str = vec[n-1];
        while (!str.empty()) {
            ans = str;

            do {
                str.pop_back();
                if (str.back() < 'Z') break;
            } while (!str.empty());

            if (str.empty()) break;
            str.back() += 1;

            if (!bigger(vec[n-1], str) || !bigger(str, vec[n]))
                break;
            
        }
        cout << ans << '\n';
    }

    return 0;
}
