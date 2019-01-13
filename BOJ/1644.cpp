#define MAX 4000000

#include <iostream>
#include <vector>

int main() {
    int n, sum = 0, ans = 0;
    std::vector<bool> isPrime(MAX+1, true);
    std::vector<int> primes;
    
    scanf("%d", &n);
    
    for (int i = 2; i*i <=MAX; i++) {
        if (isPrime[i]) {
            for (int j = i+i; j <= MAX; j+=i)
                isPrime[j] = false;
        }
    }
    
    for (int i = 2; i <= MAX; i++) {
        if (isPrime[i]) primes.push_back(i);
    }
    
    for (int i = 0; i < primes.size(); i++) {
        sum = 0;
        for (int j = i; j < primes.size(); j++) {
            sum += primes[j];
            if (n <= sum) break;
        }
        
        if (n == sum) ans++;
    }
    
    printf("%d", ans);
    
    return 0;
}
