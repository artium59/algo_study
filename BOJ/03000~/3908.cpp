#include <iostream>
#include <vector>
using namespace std;

int t, n, k, dp[1121][15];
bool b[1121];
vector<int> prime;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    prime.push_back(2);
    for (int i = 3; i < 1121; i+=2) {
        if (!b[i]) {
            prime.push_back(i);
            for (int j = i+i; j < 1121 && i*i < 1121; j+=i) b[j] = true;
        }
    }

    for (int j = 0; j < 15; j++) {
        for (int i = 0; i < 1121; i++) dp[i][j] = 0;
    }

    for (int k = 0; k < prime.size(); k++) {
        for (int j = min(15,k+2); j > 1; j--) {
            for (int i = 2; i+prime[k] < 1121; i++)
                dp[i+prime[k]][j] += dp[i][j-1];
        }

        dp[prime[k]][1] = 1;
    }

    cin >> t;
    while(t--) {
        cin >> n >> k;
        cout << dp[n][k] << "\n";
    }

    return 0;
}
