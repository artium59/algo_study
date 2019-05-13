#include <iostream>
#include <vector>
using namespace std;

const int MAX = 5000000;
int n, k, low, loc, size;
bool isPrime[MAX+1];
vector<int> prime;

int main() {
    for (int i = 3; i*i <= MAX; i+=2) {
        if (!isPrime[i]) {
            for (int j = i+i; j <= MAX; j+=i)
                isPrime[j] = true;
        }
    }

    prime.push_back(2);
    for (int i = 3; i <= MAX; i+=2) {
        if (!isPrime[i]) prime.push_back(i);
    }

    scanf("%d", &n);
    size = prime.size();
    while (n--) {
        loc = 0;
        scanf("%d", &k);

        low = lower_bound(prime.begin(), prime.end(), k) - prime.begin();
        while (k > 1 && loc < size && k != prime[low]) {
            if (k % prime[loc] == 0) {
                k /= prime[loc];
                low = lower_bound(prime.begin(), prime.end(), k) - prime.begin();

                printf("%d", prime[loc]);
                if (k > 1) printf(" ");
            }
            else {
                loc++;
            }
        }

        if (k > 1) printf("%d", k);
        printf("\n");
    }

    return 0;
}
