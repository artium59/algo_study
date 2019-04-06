#include <cstdio>
#include <algorithm>
#include <vector>

int ans = 0;
bool prime[1001];

int main() {
    int n, t;
    std::vector<int> vec;

    std::fill(prime, prime+1001, true);

    prime[0] = prime[1] = false;
    for (int i = 2; i*i < 1001; i++) {
        if (prime[i]) {
            for (int j = i+i; j < 1001; j+=i)
                prime[j] = false;
        }
    }

    scanf("%d", &n);
    while (n--) {
        scanf("%d", &t);
        vec.push_back(t);
    }

    std::for_each(vec.begin(), vec.end(), [](const auto& v) {
        if (prime[v]) ans++;
    });
	
    printf("%d", ans);

    return 0;
}
