#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int n, d, ans;
pair<int, int> arr[100000];
priority_queue<int> pq;

int main(void) {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d %d", &arr[i].first, &arr[i].second);
        if (arr[i].first > arr[i].second)
            swap(arr[i].first, arr[i].second);
    }
    scanf("%d", &d);

    sort(arr, arr+n, [](const auto& a, const auto& b) {
        if (a.second != b.second) return a.second < b.second;
        else return a.first < b.first;
    });

    for (int i = 0; i < n; ++i) {
        if (arr[i].second - arr[i].first > d) continue;
        while (!pq.empty() && arr[i].second + pq.top() > d) pq.pop();
        pq.push(-arr[i].first);
        ans = max(ans, (int)pq.size());
    }

    printf("%d", ans);
    return 0;
}
