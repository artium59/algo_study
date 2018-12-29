#include <iostream>
#include <algorithm>
#include <vector>

int main() {
    int n, m, t, left, right, mid;
    bool isFind;
    std::vector<int> cards, detects, ans;

    scanf("%d", &n);
    for (int h = 0; h < n; h++) {
        scanf("%d", &t);
        cards.push_back(t);
    }

    scanf("%d", &m);
    for (int h = 0; h < m; h++) {
        scanf("%d", &t);
        detects.push_back(t);
    }

    sort(cards.begin(), cards.end());

    for (const auto& d : detects) {
        left = 0; right = n-1;
        while (left <= right) {
            isFind = false;
            mid = (left + right) / 2;
            if (d > cards[mid]) left = mid + 1;
            else if (d < cards[mid]) right = mid - 1;
            else {
                isFind = true;
                break;
            }
        }

        ans.push_back(isFind ? 1 : 0);
    }

    for (const auto& a : ans)
        printf("%d\n", a);

    return 0;
}
