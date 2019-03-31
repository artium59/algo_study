#include <iostream>
#include <algorithm>
#include <vector>

int main() {
    int n, t, size = 0, ans = 1;
    std::vector<int> arr;

    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &t);

        for (int j = 0; j < size; j++)
            arr.push_back(arr[j]+t);
        arr.push_back(t);

        size = arr.size();
    }

    sort(arr.begin(), arr.end());
    std::unique(arr.begin(), arr.end());

    for (const auto& a : arr) {
        if (a != ans) break;
        ans++;
    }

    printf("%d", ans);

    return 0;
}

