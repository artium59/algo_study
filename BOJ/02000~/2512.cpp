#include <iostream>
#include <algorithm>
#include <vector>

int main() {
    int n, m, t, left = 0, right = 0, mid, ans, sum;
    std::vector<int> budgets;

    scanf("%d", &n);
    for (int h = 0; h < n; h++) {
        scanf("%d", &t);
        budgets.push_back(t);
        
        if (right < t) right = t;
    }
    scanf("%d", &m);

    while (left <= right) {
        sum = 0;
        mid = (left + right) / 2;

        for (const auto& b : budgets)
            sum += b < mid ? b : mid;

        if (sum < m) left = mid + 1;
        else if (sum > m) right = mid - 1;
        else break;
    }

    sum = 0;
    for (const auto& b : budgets)
        sum += b < mid ? b : mid;

    printf("%d", sum > m ? mid-1 : mid);

    return 0;
}
