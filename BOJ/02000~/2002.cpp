#include <iostream>
#include <map>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, arr[1000], ans = 0;
    string str;
    map<string, int> order;

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> str;
        order.insert(make_pair(str, i));
    }
    for (int i = 0; i < n; i++) {
        cin >> str;
        arr[i] = order[str];
    }

    for (int i = 0; i < n-1; i++) {
        for (int j = i+1; j < n; j++) {
            if (arr[i] > arr[j]) {
                ans++; break;
            }
        }
    }

    cout << ans;

    return 0;
}
