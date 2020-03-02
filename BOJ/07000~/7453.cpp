#include <cstdio>
#include <algorithm>
#include <vector>

long long ans;
int n, A[4000], B[4000], C[4000], D[4000];
std::vector<int> CD;

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d %d %d %d", A+i, B+i, C+i, D+i);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            CD.push_back(C[i]+D[j]);
    }
    sort(CD.begin(), CD.end());

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            auto left = lower_bound(CD.begin(), CD.end(), -A[i]-B[j]);
            auto right = upper_bound(CD.begin(), CD.end(), -A[i]-B[j]);

            ans += right - left;
        }
    }

    printf("%lld", ans);
    return 0;
}
