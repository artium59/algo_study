#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int i = 0;
    bool isLove = false;
    string str, ucpc = "UCPC";

    getline(cin, str);

    for (const auto& s : str) {
        if (s == ucpc[i]) i++;
        if (i == 4) { isLove = true; break; }
    }

    isLove ? cout << "I love UCPC" : cout << "I hate UCPC";

    return 0;
}
