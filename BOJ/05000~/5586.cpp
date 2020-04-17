#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int a = 0, b = 0;
    string str;
    cin >> str;
    for (int i = 0; i <= str.size()-3; i++) {
        if (str[i] == 'J' && str[i+1] == 'O' && str[i+2] == 'I') ++a;
        if (str[i] == 'I' && str[i+1] == 'O' && str[i+2] == 'I') ++b;
    }

    cout << a << '\n' << b;

    return 0;
}
