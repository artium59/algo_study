#include <iostream>
using namespace std;

inline int max(int a, int b) { return a > b ? a : b; }

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, ans = 0, left = 0, right = 0;
    string str;

    cin >> n >> str;

    while (str[left] == 'V') { left++; }
    right = left;

    while (right+1 < n) {
        if (str[right] == str[right+1] || str[right] == 'V' || str[right+1] == 'V') {
            left = right+1;
            right = left;
        }
        else
            right++;

        ans = max(ans, right-left);
    }

    cout << ans+1;

    return 0;
}
