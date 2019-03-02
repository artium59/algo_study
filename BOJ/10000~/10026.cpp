#include <iostream>
#include <cstring>
#include <queue>

short picture[102][102];
int xrr[4] = { 1, -1, 0, 0 }, yrr[4] = { 0, 0, 1, -1 };
bool visited[102][102];

void See(int b, int a) {
    int x, y;
    std::queue<std::pair<int, int>> q;
    q.push(std::make_pair(b, a));
    
    while (!q.empty()) {
        y = q.front().first;
        x = q.front().second;
        q.pop();
        
        if (visited[y][x]) continue;
        visited[y][x] = true;
        
        for (int i = 0; i < 4; i++) {
            if (picture[y-yrr[i]][x-xrr[i]] == picture[y][x])
                q.push(std::make_pair(y-yrr[i], x-xrr[i]));
        }
    }
}

void Blindness(int b, int a) {
    int x, y;
    bool swch = false;
    std::queue<std::pair<int, int>> q;
    q.push(std::make_pair(b, a));
    
    if (picture[b][a] > 0) swch = true;
    
    while (!q.empty()) {
        y = q.front().first;
        x = q.front().second;
        q.pop();
        
        if (visited[y][x]) continue;
        visited[y][x] = true;
        
        for (int i = 0; i < 4; i++) {
            if (swch) {
                if (picture[y-yrr[i]][x-xrr[i]] > 0)
                    q.push(std::make_pair(y-yrr[i], x-xrr[i]));
            }
            else {
                if (picture[y-yrr[i]][x-xrr[i]] == 0)
                    q.push(std::make_pair(y-yrr[i], x-xrr[i]));
            }
        }
    }
}

int main() {
    int n, a = 0, b = 0;
    char ch;

    memset(picture, -1, sizeof(picture));
    
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            scanf(" %c", &ch);
            if (ch == 'R') picture[i][j] = 1;
            else if (ch == 'G') picture[i][j] = 2;
            else picture[i][j] = 0;
        }
    }
    
    memset(visited, false, sizeof(visited));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (!visited[i][j]) {
                See(i, j); a++;
            }
        }
    }
    
    memset(visited, false, sizeof(visited));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (!visited[i][j]) {
                Blindness(i, j); b++;
            }
        }
    }
    
    
    printf("%d %d", a, b);

    return 0;
}
