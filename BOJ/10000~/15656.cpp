#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n, m;
vector<int> arr;

void Print(int cnt, string str) {
    if (cnt == m) {
        cout << str << "\n"; return;
    }

    for (int i = 0; i < n; i++) {
        string s = str;

        if (cnt > 0) s += " ";
        s += to_string(arr[i]);
        Print(cnt+1, s);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    string s;

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> t;
        arr.push_back(t);
    }

    sort(arr.begin(), arr.end());

    Print(0, s);

    return 0;
}