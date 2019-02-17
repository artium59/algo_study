#include <iostream>

using namespace std;

void Print(int n, int m, int cnt, string str) {
    if (cnt == m) {
        cout << str << "\n"; return;
    }

    for (int i = 1; i <= n; i++) {
        string s = str;

        if (cnt > 0) s += " ";
        s += i + '0';
        Print(n, m ,cnt+1, s);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    string s;

    cin >> n >> m;

    Print(n, m, 0, s);

    return 0;
}