#include <iostream>
#include <map>
using namespace std;

int n, m;
string str, ans, arr[100001];
map<string, int> dict;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
        dict.insert(make_pair(arr[i], i));
    }
    while (m--) {
        cin >> str;

        try {
            n = stoi(str, nullptr);
            ans = arr[n];
        }
        catch(exception& e) {
            ans = to_string(dict[str]);
        }

        cout << ans << "\n";
    }

    return 0;
}
