#include <iostream>
#include <cmath>
#include <vector>

int main() {
    int n, s, t, start = 0, end = 0, sum = 0, ans;
    std::vector<int> arr;

    scanf("%d %d", &n, &s);
    for (int i = 0; i < n; i++) {
        scanf("%d", &t);
        arr.push_back(t);
    }

    ans = n+1;
    while (end <= n) {
        if (sum < s) {
            if (end < n) {
                sum += arr[end];
                end++;
            }
            else
                break;
        }
        else {
            ans = std::min(end - start, ans);
            sum -= arr[start];
            start++;
            if (start > end) end = start;
        }
    }

    ans = (ans == n+1) ? 0 : ans;

    printf("%d", ans);

    return 0;
}
