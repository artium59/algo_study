#define MAX 1000000

#include <iostream>
#include <vector>

using namespace std;

int Divide(string str, int d) {
    int ret = 0;
    
    for (const auto& s : str)
        ret = (ret * 10 + (s - '0')) % d;
    
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    string p;
    int k, ans;
    bool isGood = true;
    vector<bool> isPrime(MAX+1, true);
    vector<int> primes;
    
    cin >> p >> k;
    
    for (int i = 2; i*i <= MAX; i++) {
        if (isPrime[i]) {
            for (int j = i+i; j <= MAX; j+=i)
                isPrime[j] = false;
        }
    }
    
    for (int i = 2; i <= MAX; i++) {
        if (isPrime[i]) primes.push_back(i);
    }
    
    for (const auto& prime : primes) {
        if (prime < k) {
            if (Divide(p, prime) == 0) {
                isGood = false; ans = prime;
                break;
            }
        }
        else
            break;
    }
    
    isGood ? cout << "GOOD" : cout << "BAD " << ans;
}
