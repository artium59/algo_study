#include <iostream>
#include <vector>

int max(int a, int b) {
    return a > b ? a : b;
}

int main() {
    int n, k, w, v, ans = 0;
    std::vector<int> arr(100001, 0);
    std::vector<std::pair<int, int>> things;

    scanf("%d %d", &n, &k);
    for (int i = 0 ; i < n; i++) {
        scanf("%d %d", &w, &v);
        things.push_back(std::make_pair(w, v));
    }

    for (const auto& t : things) {
        for (int j = k; j >= t.first; j--) {
            arr[j] = max(arr[j], arr[j-t.first]+t.second);

            if (arr[j] > ans) ans = arr[j];
        }
    }

    printf("%d", ans);

    return 0;
}