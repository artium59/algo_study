#include <iostream>
#include <algorithm>
#include <vector>

int main() {
    int n, m, k;
    long long t, a, b, c, ans;
    std::vector<long long> arr, sum;
    std::vector<std::pair<long long, long long>> changes;
    scanf("%d %d %d", &n, &m, &k);

    for (int h = 0; h < n; h++) {
        scanf("%lld", &t);
        arr.push_back(t);

        if (h == 0) sum.push_back(t);
        else sum.push_back(t+sum[h-1]);
    }

    for (int i = 0; i < m+k; i++) {
        ans = 0;
        changes.push_back(std::make_pair(-1, -1));
        scanf("%lld %lld %lld", &a, &b, &c);

        if (a == 1) {
            for (int i = 0; i < changes.size(); i++) {
                if (changes[i].first == b-1) {
                    changes[i].second = c;
                    break;
                }
                if (i == changes.size() - 1)
                    changes.push_back(std::make_pair(b-1, c));
            }
        }
        else {
            long long temp;
            if (b < c) {
                temp = b; b = c; c = temp;
            }
            if (c > 1) ans = sum[b-1] - sum[c-2];
            else ans = sum[b-1];

            for (const auto& change : changes) {
                if (c-(long long)1 <= change.first && change.first <= b-(long long)1)
                    ans += change.second - arr[change.first];
            }
            printf("%lld\n", ans);
        }
    }

    return 0;
}
