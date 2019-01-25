#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

bool check[2][101];

void Push(int size) {
    for (int i = 0; i < size; i++)
        check[0][i] = check[1][i];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    string pattern, d;
    vector<string> ans;

    cin >> pattern >> n;
    for (int h = 0; h < n; h++) {
        cin >> d;

        memset(check, false, sizeof(check));
        check[0][0] = true;

        for (const auto& p : pattern) {
            for (int i = 0; i < d.size() + 1; i++) {
                if (p == '*') check[1][i] = i == 0 ? check[0][i] : check[0][i] || check[1][i-1];
                else check[1][i] = (p == d[i-1] && check[0][i-1]);
            }

            Push(d.size() + 1);
        }

        if (check[1][d.size()]) ans.push_back(d);
    }

    for (const auto& a : ans)
        cout << a << "\n";

    return 0;
}
