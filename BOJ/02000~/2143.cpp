#include <iostream>
#include <algorithm>
#include <vector>

std::vector<int> A, B;

int main() {
    int t, n, m, c, start = 0, size;
    long long ans = 0;
    
    scanf("%d %d", &t, &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &c);
        size = A.size();
        if (size > 0) start += i-1;
        for (int j = start; j < size; j++)
            A.push_back(A[j] + c);
        A.push_back(c);
    }
    start = 0;
    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        scanf("%d", &c);
        size = B.size();
        if (size > 0) start += i-1;
        for (int j = start; j < size; j++)
            B.push_back(B[j] + c);
        B.push_back(c);
    }

    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    for (const auto& a : A) {
        m = lower_bound(B.begin(), B.end(), t-a) - B.begin();
        n = upper_bound(B.begin(), B.end(), t-a) - B.begin();

        ans += (n - m);
    }

    printf("%lld", ans);

    return 0;
}
