#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
using namespace std;

int n, t;
string str;
map<string, int> sum;
vector<string> serial;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    while (n--) {
        t = 0;
        cin >> str;
        serial.push_back(str);

        for (const auto& s : str) {
            if ('0'<=s&&s<='9') t += s-'0';
        }

        sum[str] = t;
    }

    sort(serial.begin(), serial.end(), [](const auto& a, const auto& b) {
        if (a.size() != b.size()) return a.size() < b.size();
        if (sum[a] != sum[b]) return sum[a] < sum[b];
        return a < b;
    });

    for_each(serial.begin(), serial.end(), [](const auto& s) { cout << s << "\n"; });

    return 0;
}
