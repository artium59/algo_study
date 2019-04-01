#include <iostream>
#include <algorithm>
#include <vector>

int q[100];

int main() {
    int n, k, t;
    bool isAns = true;
    std::vector<std::pair<int, int>> arr;

    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; i++) {
        scanf("%d", &t);
        arr.push_back(std::make_pair(t, i));
    }
	
    sort(arr.begin(), arr.end());
    std::fill(q, q+100, -1);

    for (const auto& a : arr) {
        for (int i = 0; i < k; i++) {
            if (q[i] < a.second) {
                q[i] = a.second; break;
            }
            if (i == k-1) isAns = false;
        }
        if (!isAns) break;
    }

    printf(isAns ? "YES" : "NO");

    return 0;
}
