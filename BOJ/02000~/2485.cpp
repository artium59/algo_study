#include <iostream>
#include <queue>
#include <vector>

int gcd(int a, int b) {
    if (b == 0) return a;
    else return gcd(b, a%b);
}

int main() {
    int n, t, u, first, second, ans = 0;
    std::queue<int> arr;
    std::vector<int> subs;
  
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &u);
        if (i > 0) {
          arr.push(u - t);
          subs.push_back(u - t);
        }
        t = u;
    }
    
    while (!arr.empty()) {
        first = arr.front();
        arr.pop();
        if (arr.empty()) break;
            second = arr.front();
            arr.pop();
    
        arr.push(gcd(first, second));
    }

    for (const auto& s : subs)
        ans += (s/first - 1);

    printf("%d", ans);

    return 0;
}
