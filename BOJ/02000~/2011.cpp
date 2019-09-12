#include <iostream>
using namespace std;

const long MAX = 1000000L;
string cipher;
long dp[5005];

long find(int loc) {
    if (loc == cipher.size()) return 1L;
    if (cipher[loc] == '0' || loc > cipher.size()) return 0L;
    
    long& ret = dp[loc];
    if (ret != 0) return ret;
    
    if (cipher[loc] == '1' || (cipher[loc] == '2' && cipher[loc+1] <'7'))
        ret += find(loc+2)%MAX;
    
    return ret = (ret + find(loc+1))%MAX;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> cipher;
    find(0);
    cout << dp[0]%MAX;

    return 0;
}
