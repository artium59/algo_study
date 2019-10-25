#include <cstdio>
#include <queue>

const int MAX = 1e6+1;
int n, t, dp[MAX];
std::queue<int> q;
std::deque<int> dq;

int main() {
    scanf("%d", &n);

    for (int i = 0; i < MAX; ++i) dp[i] = MAX;

    q.push(n); dp[n] = 0;
    while (!q.empty()) {
        t = q.front();
        q.pop();

        if (t < 1) continue;

        if (t%3 == 0 && dp[t/3] > dp[t]+1) dp[t/3] = dp[t]+1, q.push(t/3);
        if (t%2 == 0 && dp[t/2] > dp[t]+1) dp[t/2] = dp[t]+1, q.push(t/2);
        if (dp[t-1] > dp[t]+1) dp[t-1] = dp[t]+1, q.push(t-1);
    }

    printf("%d\n", dp[1]); t = 1;
    while (t != n) {
        dq.push_back(t);

        if (t*3 < MAX && dp[t*3] == dp[t]-1) t *= 3;
        else if (t*2 < MAX && dp[t*2] == dp[t]-1) t *= 2;
        else ++t;
    }

    printf("%d ", n);
    while (!dq.empty()) {
        printf("%d ", dq.back()); dq.pop_back();
    }

    return 0;
}
