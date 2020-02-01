#include <iostream>
using namespace std;
using ll = long long;

inline ll max(ll a, ll b) { return a > b ? a : b; }

int n;
ll ans = -1234567890;
ll already[19];
string fomula;

void find(int idx, ll sum) {
    if (idx >= n) {
        ans = max(ans, sum);
        return;
    }

    if (fomula[idx] == '+') {
        find(idx+2, sum+(fomula[idx+1]-'0'));
        if (idx+2 < n) find(idx+4, sum+already[idx+2]);
    }
    else if (fomula[idx] == '-') {
        find(idx+2, sum-(fomula[idx+1]-'0'));
        if (idx+2 < n) find(idx+4, sum-already[idx+2]);
    }
    else {
        find(idx+2, sum*(fomula[idx+1]-'0'));
        if (idx+2 < n) find(idx+4, sum*already[idx+2]);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> fomula;
    for (int i = 1; i < n; i+=2) {
        if (fomula[i] == '+')
            already[i] = (fomula[i-1]-'0') + (fomula[i+1]-'0');
        else if (fomula[i] == '-')
            already[i] = (fomula[i-1]-'0') - (fomula[i+1]-'0');
        else
            already[i] = (fomula[i-1]-'0') * (fomula[i+1]-'0');
    }    

    find(1, fomula[0]-'0');
    cout << ans;

    return 0;
}
