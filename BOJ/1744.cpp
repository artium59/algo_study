#include <cstdio>
#include <algorithm>
#include <vector>

int n, t;
long long ans;
std::vector<int> positive, negative;

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &t);
        if (t > 0) positive.push_back(t);
        else negative.push_back(t);
    }
    sort(positive.begin(), positive.end(), [](const auto& a, const auto& b) {
        return a > b;
    });

    sort(negative.begin(), negative.end());
    
    for (int i = 0; positive.size() > 1 && i < positive.size()-1; i+=2) {
        n = positive[i]; t = positive[i+1];

        if (n*t < n+t) ans += n+t;
        else ans += n*t;
    }
    if (positive.size() % 2 == 1) ans += positive[positive.size()-1];
    
    for (int i = 0; negative.size() > 1 && i < negative.size()-1; i+=2)
        ans += negative[i]*negative[i+1];
    if (negative.size() % 2 == 1) ans += negative[negative.size()-1];

    printf("%lld", ans);

    return 0;
}
