#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int size, ans = 0;
    bool swch;
    string str;
    cin >> str;

    size = str.size();
    sort(str.begin(), str.end());
    do {
        swch = true;

        for (int i = 0; i < size-1; i++) {
            if (str[i] == str[i+1]) {
                swch = false; break;
            }
        }

        if (swch) ans++;
    } while ( next_permutation(str.begin(), str.end()) );

    cout << ans;

    return 0;
}
