#include <iostream>
#include <vector>

using namespace std;

void Select(const vector<int>& arr, int a, int cnt, string str) {
    if (a == arr.size()+1) return;
    if (cnt == 6) { cout << str << "\n"; return; } 

    for (int i = a; i < arr.size(); i++) {
        string s = str;

        if (cnt > 0) s += " ";
        s += to_string(arr[i]);
        Select(arr, i+1, cnt+1, s);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int k, n;
    string s;

    while (true) {
        cin >> k;
        if (k == 0) break;

        vector<int> arr;

        for (int i = 0; i < k; i++) {
            cin >> n;
            arr.push_back(n);
        }

        Select(arr, 0, 0, s);
        cout << "\n";
    }

    return 0;
}