#include <iostream>
#include <queue>

bool visited[1000000];

int main() {
    int f, s, g, u, d, cnt, ans = -1;
    std::queue<std::pair<int,int>> q;

    for (int i = 0; i < 1000000; i++)
        visited[i] = false;

    scanf("%d %d %d %d %d", &f, &s, &g, &u, &d);

    q.push(std::make_pair(s, 0));
    while (!q.empty()) {
        s = q.front().first;
        cnt = q.front().second;
        q.pop();

        if (visited[s-1]) continue;
        visited[s-1] = true;

        if (s == g) {
            ans = cnt; break;
        }

        if (s - d > 0) q.push(std::make_pair(s-d, cnt+1));
        if (s + u <= f) q.push(std::make_pair(s+u, cnt+1));
    }

    ans == -1 ? printf("use the stairs") : printf("%d", ans);

    return 0;
}
