#include <cstdio>
#include <cstring>
#include <queue>

int n, k, cnt[100001];
std::queue<int> q;
std::deque<int> dq;

int main() {
    scanf("%d %d", &n, &k);

    memset(cnt, -1, sizeof(cnt));

    q.push(n); cnt[n] = 0;
    while (!q.empty()) {
        n = q.front();
        q.pop();

        if (n == k) break;

        if (n-1 >= 0 && cnt[n-1] == -1) {
            cnt[n-1] = cnt[n]+1; q.push(n-1);
        }
        if (n+1 < 100001 && cnt[n+1] == -1) {
            cnt[n+1] = cnt[n] + 1; q.push(n+1);
        }
        if (2*n < 100001 && cnt[2*n] == -1) {
            cnt[2*n] = cnt[n]+1; q.push(2*n);
        }
    }

    printf("%d\n", cnt[n]);
    while (cnt[n] != 0) {
        dq.push_back(n);

        if (n % 2 == 0 && cnt[n/2]+1 == cnt[n]) n /= 2;
        else if (n > 0 && cnt[n-1]+1 == cnt[n]) n -= 1;
        else n += 1;
    }

    printf("%d ", n);
    while (!dq.empty()) {
        printf("%d ", dq.back()); dq.pop_back();
    }

    return 0;
}
