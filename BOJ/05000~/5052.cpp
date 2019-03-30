#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int tc, n;
    bool check;
    string str;

    cin >> tc;
    while (tc--) {
        check = true;
        vector<string> vec;
		
        cin >> n;
        while (n--) {
            cin >> str;
            vec.push_back(str);
        }

        sort(vec.begin(), vec.end());

        n = vec.size();
        for (int h = 0; h < n-1; h++) {
            str = vec[h+1].substr(0, vec[h].size());
            if (vec[h] == str) {
                check = false; break;
            }
        }

        check ? cout << "YES\n" : cout << "NO\n";
    }

    return 0;
}
