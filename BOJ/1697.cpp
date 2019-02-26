#include <iostream>
#include <cstring>
#include <queue>

const int MAX = 100000;
bool visited[MAX];

int min(int a, int b) {
    return a < b ? a : b;
}

int BFS(int s, int dest) {
    int cur, ret = 0;
    std::queue<std::pair<int, int>> q;
    q.push(std::make_pair(s, 0));

    while (!q.empty()) {
        cur = q.front().first;
        ret = q.front().second;
        q.pop();
		
        if (visited[cur]) continue;
        if (cur == dest) break;
        visited[cur] = true;

        if (cur-1 >= 0) q.push(std::make_pair(cur-1, ret+1));
        if (cur+1 <= MAX) q.push(std::make_pair(cur+1, ret+1));
        if (cur*2 <= MAX) q.push(std::make_pair(2*cur, ret+1));
    }

    return ret;
}

int main() {
    int n, k;

    memset(visited, false, sizeof(visited));

    scanf("%d %d", &n, &k);
    printf("%d", BFS(n, k));

    return 0;
}