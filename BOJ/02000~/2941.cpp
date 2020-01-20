#include <iostream>
using namespace std;

int main() {
    int ans = 0;
    string str;

    cin >> str;
    for (int i = 0; i < str.size(); ++i) {
        if (str[i] == '=') {
            if (str[i-1] == 'c' || str[i-1] == 's')
                continue;
            else {
                if (i > 1 && str[i-2] == 'd') --ans;
            }
        }
        else if (str[i] == '-')
            continue;
        else if (str[i] == 'j') {
            if (i > 0 && (str[i-1] == 'l' || str[i-1] == 'n')) continue;
            else ++ans;
        }
        else ++ans;
    }

    cout << ans;

    return 0;
}
