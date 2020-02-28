#include <iostream>
#include <queue>
using namespace std;

const int MAX = 110001;
int n, k, cnt;
bool visited[MAX];
queue<pair<int, int>> q;

int main() {
    scanf("%d %d", &n, &k);
    
    q.push({ n, 0 });
    while (!q.empty()) {
        n = q.front().first;
        cnt = q.front().second;
        q.pop();

        if (n == k) break;
        for (int i = 2; i*n < min(4*k, MAX) && n != 0; i*=2) {
            if (visited[i*n]) continue;

            visited[i*n] = true;
            q.push({ i*n, cnt });
        }
        if (n+1 <= k && !visited[n+1]) {
            visited[n+1] = true;
            q.push({ n+1, cnt+1 });
        }
        if (0 <= n-1 && !visited[n-1]) {
            visited[n-1] = true;
            q.push({ n-1, cnt+1 });
        }
    }

    printf("%d", cnt);

    return 0;
}
