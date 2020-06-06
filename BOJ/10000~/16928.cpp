#include <cstdio>
#include <queue>

int n, m, a, b, board[101];
bool visited[101];
std::queue<int> q;

int main(void) {
    for (int i = 1; i < 101; ++i)
        board[i] = i;

    scanf("%d %d", &n, &m); n += m;
    while(n--) {
        scanf("%d %d", &a, &b);
        board[a] = b;
    }

    q.push(1);
    for (b = 0; ; ++b) {
        m = q.size();
        for (int k = 0; k < m; ++k) {
            a = q.front();
            q.pop();

            if (a == 100) goto ANS;

            for (int i = 1; i <= 6; ++i) {
                if (a+i > 100) break;
                if (visited[board[a+i]]) continue;

                visited[board[a+i]] = true;
                q.push(board[a+i]);
            }
        }
    }

    ANS:
    printf("%d", b);
    return 0;
}
