#include <iostream>
using namespace std;

int n, m, a, b, ans, arr[200][200];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    while (m--) {
        cin >> a >> b; --a; --b;
        arr[a][b] = arr[b][a] = -1;
    }

    for (int i = 0; i < n; ++i) {
        for (int j = i+1; j < n; ++j) {
            if (arr[i][j] == -1) continue;

            for (int k = j+1; k < n; ++k) {
                if (arr[i][k] == 0 && arr[j][k] == 0)
                    ++ans;
            }
        }
    }

    cout << ans;
    return 0;
}
