#include <iostream>
#include <cstring>
using namespace std;

const int MAX = 10000000;
int tc;
string ss;
bool not_prime[MAX], visited[10], check[MAX];

int find(string str) {
    int sum=0, ret=0;

    for (const auto& s : str) {
        sum *= 10;
        sum += s - '0';
    }

    if (!check[sum]) {
        check[sum] = true;
        if ((!not_prime[sum] && sum % 2 == 1) || sum == 2) ++ret;
    }
    if (str.size() >= ss.size()) return ret;

    for (int i = 0; i < ss.size(); ++i) {
        if (visited[i]) continue;

        visited[i] = true;
        ret += find(str+ss[i]);
        visited[i] = false;
    }

    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    not_prime[0] = not_prime[1] = true;
    for (int i = 3; i*i < MAX; i+=2) {
        if (not_prime[i]) continue;

        for (int j = i+i; j < MAX; j+=i)
            not_prime[j] = true;
    }

    cin >> tc;
    while (tc--) {
        memset(check, false, sizeof(check));
        cin >> ss;
        cout << find("") << "\n";
    }

    return 0;
}
