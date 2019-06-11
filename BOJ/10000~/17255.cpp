#include <iostream>
using namespace std;

int ans = 0;
string num;

void Find(string str) {
    if (str.size() == 1) {
        ans++; return;
    }
    string l, r = str;

    r.pop_back();
    for (int i = 1; i < str.size(); i++)
        l += str[i];

    Find(l);
    if (l != r) Find(r);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> num;

    Find(num);
    cout << ans;

    return 0;
}
