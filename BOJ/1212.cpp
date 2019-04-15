#include <iostream>
using namespace std;

const string bin[8] = { "000", "001", "010", "011", "100", "101", "110", "111" };
const string first[8] = { "0", "1", "10", "11", "100", "101", "110", "111" };

string str;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> str;

    cout << first[str[0]-'0'];
    for (int i = 1; i < str.size(); i++)
        cout << bin[str[i]-'0'];

    return 0;
}
