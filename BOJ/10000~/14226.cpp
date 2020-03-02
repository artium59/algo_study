#include <iostream>
#include <queue>
using namespace std;

int s, t, cur, clip, size;
bool loop=true, visited[1101][1001];
queue<pair<int, int>> q;

int main() {
    scanf("%d", &s);

    q.push({ 1, 0 });
    for ( ; ; ++t) {
        size = q.size();
        for (int i = 0; i < size; ++i) {
            cur = q.front().first;
            clip = q.front().second;
            q.pop();

            if (cur == s) { loop = false; break; }

            if (cur < 1000 && !visited[cur][cur]) {
                visited[cur][cur] = true;
                q.push({ cur, cur });
            }
            if (clip > 0 && cur+clip < 1101 && !visited[cur+clip][clip]) {
                visited[cur+clip][clip] = true;
                q.push({ cur+clip, clip });
            }
            if (cur-1 > 0 && !visited[cur-1][clip]) {
                visited[cur-1][clip] = true;
                q.push({ cur-1, clip });
            }
        }

        if (!loop) break;
    }

    printf("%d", t);

    return 0;
}
