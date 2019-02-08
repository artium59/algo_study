#include <iostream>
#include <queue>
#include <vector>

int main() {
    int n, t, sum = 0;
    std::queue<int> arr;
    std::vector<int> ans;
  
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &t);
        arr.push(t);
    }
  
    t = 1;
    while (!arr.empty()) {
        int top = arr.front();
        arr.pop();
        ans.push_back(top*t - sum);
        sum = top*t; t++;
    }
  
    for (const auto& a : ans)
        printf("%d ", a);
  
    return 0;
}
