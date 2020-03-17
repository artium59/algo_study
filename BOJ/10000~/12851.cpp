#include <cstdio>
#include <queue>
using namespace std;

int n, k, sec[100001], cnt[100001];
queue<int> q;

int main() {
    scanf("%d %d", &n, &k);
    
    cnt[n] = 1;
    q.push(n);

    while (!q.empty()) {
        n = q.front();
        q.pop();

        if (n == k) continue;

        if (n != 0 && n*2 < 100001) {
            if (sec[n*2] == 0) {
                sec[n*2] = sec[n]+1;
                cnt[n*2] += cnt[n];
                q.push(n*2);
            }
            else if (sec[n*2] == sec[n]+1)
                cnt[n*2] += cnt[n];
        }

        if (0 < n) {
            if (sec[n-1] == 0) {
                sec[n-1] = sec[n]+1;
                cnt[n-1] += cnt[n];
                q.push(n-1);
            }
            else if (sec[n-1] == sec[n]+1)
                cnt[n-1] += cnt[n];
        }

        if (n < 100000) {
            if (sec[n+1] == 0) {
                sec[n+1] = sec[n]+1;
                cnt[n+1] += cnt[n];
                q.push(n+1);
            }
            else if (sec[n+1] == sec[n]+1)
                cnt[n+1] += cnt[n];
        }
    }

    printf("%d\n%d", sec[k], cnt[k]);
    return 0;
}
