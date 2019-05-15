#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

queue<string> line;
vector<string> order, waiting;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, ohead = 0;
    string str;

    cin >> n;
    for (int h = 0; h < n; h++) {
        for (int i = 0; i < 5; i++) {
            cin >> str;
            line.push(str);
            order.push_back(str);
        }
    }

    sort(order.begin(), order.end(), [](const auto& a, const auto& b) {
        if (a[0] != b[0]) return a[0] < b[0];
        else {
            if (a.size() != b.size()) return a.size() < b.size();
            else return a < b;
        }
    });

    for ( ; ohead < 5*n; ohead++) {
        if (!line.empty() && line.front() == order[ohead])
            line.pop();
        else {
            if (!waiting.empty() && waiting.back() == order[ohead])
                waiting.pop_back();
            else {
                while (!line.empty() && line.front() != order[ohead]) {
                    waiting.push_back(line.front());
                    line.pop();
                }

                if (line.empty()) break;

                line.pop();
            }
        }
    }

    if (ohead == 5*n) cout << "GOOD";
    else cout << "BAD";

    return 0;
}
