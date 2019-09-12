#include <cstdio>
#include <algorithm>
#include <vector>

int main() {
    int n, m, a, b, ans;
    std::vector<int> six, one;
    
    scanf("%d %d", &n, &m);
    while (m--) {
        scanf("%d %d", &a, &b);
        six.push_back(a);
        one.push_back(b);
    }

    sort(six.begin(), six.end());
    sort(one.begin(), one.end());
    
    ans = std::min(one[0]*n, six[0]*(n/6+(n%6>0 ? 1 : 0)));
    ans = std::min(ans, six[0]*(n/6)+one[0]*(n%6));
    
    printf("%d", ans);

    return 0;
}
