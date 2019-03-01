#include <stdio.h>
#include <cstring>
#include <queue>

struct Coo {
    int x, y, z;
    Coo(int a, int b, int c) : z(a), y(b), x(c) {}
};

int n, m, h;
int tomato[102][102][102];
bool visited[102][102][102];
std::queue<Coo> q;

int max(int a, int b) {
    return a > b ? a : b;
}

void Ripe() {
    int x, y, z, ret;
  
    while (!q.empty()) {
        z = q.front().z;
        y = q.front().y;
        x = q.front().x;
        q.pop();
    
        if (tomato[z-1][y][x] == 0)  {
            q.push(Coo(z-1, y, x));
            tomato[z-1][y][x] = tomato[z][y][x] + 1;
        }
    
        if (tomato[z+1][y][x] == 0)  {
            q.push(Coo(z+1, y, x));
            tomato[z+1][y][x] = tomato[z][y][x] + 1;
        }
    
        if (tomato[z][y+1][x] == 0)  {
            q.push(Coo(z, y+1, x));
            tomato[z][y+1][x] = tomato[z][y][x] + 1;
        }
    
        if (tomato[z][y-1][x] == 0)  {
            q.push(Coo(z, y-1, x));
            tomato[z][y-1][x] = tomato[z][y][x] + 1;
        }
    
        if (tomato[z][y][x+1] == 0)  {
            q.push(Coo(z, y, x+1));
            tomato[z][y][x+1] = tomato[z][y][x] + 1;
        }
    
        if (tomato[z][y][x-1] == 0)  {
            q.push(Coo(z, y, x-1));
            tomato[z][y][x-1] = tomato[z][y][x] + 1;
        }
    }
}

int main() {
    int ans = 0;
  
    memset(tomato, -1, sizeof(tomato));
    memset(visited, false, sizeof(visited));
  
    scanf("%d %d %d", &m, &n, &h);
    for (int k = 1; k <= h; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                scanf("%d", &tomato[k][i][j]);
                if (tomato[k][i][j] == 1) q.push(Coo(k, i, j));
            }
        }
    }
  
    Ripe();
  
    for (int k = 1; k <= h; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                ans = max(ans, tomato[k][i][j]);
                if (tomato[k][i][j] == 0) {
                    ans = 0; goto Ans;
                }
            }
        }
    }

    Ans:
    printf("%d", ans-1);

    return 0;
}
