#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n, m;
bool isChosen[8];
vector<int> arr;

void Print(int cnt, string str) {
    if (cnt == m) {
        cout << str << "\n"; return;
    }

    for (int i = 0; i < n; i++) {
        string s = str;

        if (!isChosen[i]) {
            if (cnt > 0) s += " ";
            s += to_string(arr[i]);
            isChosen[i] = true;
            Print(cnt+1, s);
            isChosen[i] = false;
        }
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

    fill(isChosen, isChosen+8, false);
    sort(arr.begin(), arr.end());

    Print(0, s);

    return 0;
}