#define MAX 10000000

#include <iostream>
#include <vector>

int main() {
    int n, k = 0;
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
    
    while (n > 1) {
        if (n % primes[k] == 0) { printf("%d\n", primes[k]); n /= primes[k]; }
        else k++;
    }
    
    return 0;
}
