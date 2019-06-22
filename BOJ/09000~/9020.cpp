#include <iostream>
#include <vector>

int t, n, a, x, y;
bool b[10001];
std::vector<int> prime(1, 2);

int main() {
    for (int i = 3; i*i < 10001; i+=2) {
        if (!b[i]) {
            for (int j = i+i; j < 10001; j+=i)
                b[j] = true;
        }
    }

    for (int i = 3; i < 10001; i+=2) {
        if (!b[i]) prime.push_back(i);
    }

    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        for (const auto& p : prime) {
            if (p > n) break;

            a = std::lower_bound(prime.begin(), prime.end(), n-p) - prime.begin();
            if (p > n/2) break;
            if (p+prime[a] == n) { x = p; y = prime[a]; }
        }

        printf("%d %d\n", x, y);
    }

    return 0;
}
