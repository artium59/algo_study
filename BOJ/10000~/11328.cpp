#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    bool check;
    string a, b;

    cin >> t;
    for (int h = 0; h < t; h++) {
        check = true;
        cin >> a >> b;

        if (a.size() != b.size())
            cout << "Impossible\n";
        else {
            sort(a.begin(), a.end());
            sort(b.begin(), b.end());

            for (int i = 0; i < a.size(); i++) {
                if (a[i] != b[i]) { check = false; break; }
            }

            check ? cout << "Possible\n" : cout << "Impossible\n";
        }
    }

    return 0;
}
