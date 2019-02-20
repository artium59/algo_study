#include <iostream>
#include <cstring>
#include <queue>

int main() {
    int n, g, d, ans = 0;
    bool isGet[20000];
    std::priority_queue<std::pair<int, int>> cows;

    memset(isGet, false, sizeof(isGet));

    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &g, &d);
        cows.push(std::make_pair(g, d));
    }

    while (!cows.empty()) {
        g = cows.top().first;
        d = cows.top().second;
        cows.pop();

        if (!isGet[d]) {
            isGet[d] = true; ans += g;
        }
        else {
            for (int i = d-1; i > 0; i--) {
                if (!isGet[i]) {
                    isGet[i] = true; ans += g; break;
                }
            }
        }
    }

    printf("%d", ans);

    return 0;
}
