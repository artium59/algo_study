#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int size, cnt;
    string str, sub;

    while (true) {
        cnt = 0;
        std::queue<string> numbers[10];

        cin >> str;
        if (str == "0") break;

        size = str.size();
        for (int i = 0; i < size; i++) {
            for (int j = i; j < size; j++) {
                if (str[j] == '+') {
                    sub = str.substr(i, j-i);
                    i = j; break;
                }
                else if (j == size-1) {
                    sub = str.substr(i, j-i+1);
                    i = j; break;
                }
            }

            numbers[sub[sub.size()-1]-'0'].push(sub);
            cnt++;
        }

        while (!numbers[0].empty()) {
            cout << numbers[0].front();
            numbers[0].pop(); cnt--;
            if (cnt > 0) cout << "+";
        }

        for (int i = 1; i < 5; i++) {
            while (!numbers[i].empty() && !numbers[10-i].empty()) {
                cout << numbers[i].front() << "+" << numbers[10-i].front();
                numbers[i].pop(); numbers[10-i].pop(); cnt -= 2;
                if (cnt > 0) cout << "+";
            }
        }

        while (!numbers[5].empty()) {
            cout << numbers[5].front();
            numbers[5].pop(); cnt--;
            if (cnt > 0) cout << "+";
        }

        for (int i = 1; i < 10; i++) {
            while (!numbers[i].empty()) {
                cout << numbers[i].front();
                numbers[i].pop(); cnt--;
                if (cnt > 0) cout << "+";
            }
        }

        cout << "\n";
    }

    return 0;
}
