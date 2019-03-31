#include <iostream>
#include <utility>
using namespace std;

void PrintZero(int s) {
    for (int i = 0; i < s; i++)
        cout << "0";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string a, b, c;
    cin >> a >> b >> c;

    if (b == "+") {
        if (a.size() < c.size()) swap(a, c);

        if (a.size() != c.size()) {
            cout << "1";
            PrintZero(a.size()-c.size()-1);
            cout << "1";
            PrintZero(c.size()-1);
        }
        else {
            cout << "2";
            PrintZero(a.size()-1);
        }
    }
    else {
        cout << "1";
        PrintZero(a.size()+c.size()-2);
    }

    return 0;
}
