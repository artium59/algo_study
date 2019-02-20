#include <iostream>

using namespace std;

int n, m;

void Print(int start, int cnt, string str) {
    if (cnt == m) {
        cout << str << "\n"; return;
    }

    for (int i = start; i <= n; i++) {
        string s = str;

        if (cnt > 0) s += " ";
        s += i + '0';
        Print(i, cnt+1, s);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s;

    cin >> n >> m;

    Print(1, 0, s);

    return 0;
}