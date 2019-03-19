#include <stdio.h>
#include <cstring>
#include <queue>

struct Coo {
    int x, y, cnt;
    Coo(int b, int a, int c) : y(b), x(a), cnt(c) {}
};

bool map[52][52], visited[52][52];
int xrr[4] = { 1, -1, 0, 0 }, yrr[4] = { 0, 0, 1, -1 };
std::priority_queue<int> ans;

void FindDist(int b, int a) {
    int x, y, cnt;
    std::queue<Coo> q;
    q.push(Coo(b, a, 0));
  
    memset(visited, false, sizeof(visited));
  
    while (!q.empty()) {
        y = q.front().y;
        x = q.front().x;
        cnt = q.front().cnt;
        q.pop();
    
        if (visited[y][x]) continue;
        visited[y][x] = true;
    
        for (int i = 0; i < 4; i++) {
            if (map[y-yrr[i]][x-xrr[i]] && !visited[y-yrr[i]][x-xrr[i]])
                q.push(Coo(y-yrr[i], x-xrr[i], cnt+1));
        }
    }
  
    ans.push(cnt);
}

int main() {
    int m, n;
    char ch;
  
    memset(map, false, sizeof(map));
  
    scanf("%d %d", &m, &n);
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            scanf(" %c", &ch);
            if (ch == 'L') map[i][j] = true;
        }
    }
  
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (map[i][j]) FindDist(i, j);
        }
    }
  
    printf("%d", ans.top());
  
    return 0;
}
