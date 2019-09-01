#include <cstdio>
#include <queue>

int n, k, t=0, cnt;
std::queue<int> q[2];

int main() {
    scanf("%d %d", &n, &k);
    for (int i = 1; i <= n; i++) q[0].push(i);
    
    printf("<");
    while (!q[0].empty() || !q[1].empty()) {
        cnt = 0;
        
        while (!q[t].empty()) {
            if (cnt == k-1) {
                printf("%d", q[t].front());
                q[t].pop(); break;
            }

            q[(t+1)%2].push(q[t].front());
            q[t].pop(); cnt++;
            
            if (q[t].empty()) t = (t+1)%2;
        }
        
        if (q[t].empty()) t = (t+1)%2;
        if (!q[0].empty() || !q[1].empty()) printf(", ");
    }
    printf(">");
    
    return 0;
}
