#include <iostream>
#include <queue>

const int MAX = 1e9;
int a, b, c;
std::queue<std::pair<int, int>> q;

int main() {
    scanf("%d %d", &a, &b);

    q.push({ a, 1 });
    while (!q.empty()) {
        a = q.front().first;
        c = q.front().second;
        q.pop();

        if (a > b) continue;
        else if (a == b) { printf("%d", c); return 0; }

        q.push({ a*2, c+1 });
        if (a > MAX/10) continue;
        q.push({ a*10+1, c+1});
    }

    printf("-1");
    return 0;
}
