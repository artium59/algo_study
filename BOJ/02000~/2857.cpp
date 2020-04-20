#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string str;
    bool check = false;

    for (int k = 0; k < 5; k++) {
        cin >> str;
        for (int i = 0; i <= str.size()-3; i++) {
            if (str[i] == 'F' && str[i+1] == 'B' && str[i+2] == 'I') {
                check = true;
                cout << k+1 << '\n';
                break;
            }
        }
    }

    if (!check)
        cout << "HE GOT AWAY!";

    return 0;
}
