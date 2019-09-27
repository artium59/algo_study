#include <cstdio>
#include <queue>

int n, m, a, b, ans=0;
std::priority_queue<std::pair<int, int>> pq;

int main() {
    scanf("%d", &n);
    while (n--) {
        scanf("%d %d", &a, &b);
        pq.push({b, a});
    }
    
    n = m = 1e9;
    while (!pq.empty()) {
        b = pq.top().first;
        a = pq.top().second;
        pq.pop();
        
        if (b < n) {
            ans += m-n;
            n = a; m = b;
        }
        else {
            if (a < n) n = a;
        }
    }
    
    printf("%d", ans+m-n);

    return 0;
}
