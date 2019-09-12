#include <cstdio>
#include <queue>

inline int abs(int a) { return a < 0 ? -a : a; }

int n, k, cur, t, angle[10];
bool visited[361];
std::queue<int> q;

int main() {
    
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; i++) {
        scanf("%d", angle+i);
        q.push(angle[i]);
    }
    
    while (!q.empty()) {
        t = q.front();
        q.pop();
        
        for (int i = 0; i < n; i++) {
            cur = t + angle[i];
            if (cur > 360) cur -= 360;
            
            if (!visited[cur]) {
                visited[cur] = true;
                q.push(cur);
            }
            
            cur = abs(t-angle[i]);
            if (!visited[cur]) {
                visited[cur] = true;
                q.push(cur);
            }
        }
    }
    
    while (k--) {
        scanf("%d", &t);
        printf(visited[t] ? "YES\n" : "NO\n");
    }

    return 0;
}
