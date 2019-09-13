#include <cstdio>
#include <tuple>
#include <queue>
using namespace std;

const int xrr[4] = { 1, -1, 0, 0 }, yrr[4] = { 0, 0, 1, -1};
int x, y;
char land[10][10];
bool visited[10][10];

int BFS() {
    int nx, ny, cost;
    queue<tuple<int, int, int>> q;
    
    q.push(make_tuple(y, x, 0));
    visited[y][x] = true;
    
    while (!q.empty()) {
        y = get<0>(q.front());
        x = get<1>(q.front());
        cost = get<2>(q.front());
        q.pop();
        
        if (land[y][x] == 'B') break;
        
        for (int i = 0 ; i < 4; i++) {
            ny = y + yrr[i]; nx = x + xrr[i];
            
            if (0<=ny&&ny<10 && 0<=nx&&nx<10 && land[ny][nx] != 'R' && !visited[ny][nx]) {
                visited[ny][nx] = true;
                q.push(make_tuple(ny, nx, cost+1));
            }
        }
    }
    
    return cost;
}

int main() {
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            scanf(" %c", &land[i][j]);
            if (land[i][j] == 'L') { y = i; x = j; }
        }
    }
    printf("%d", BFS()-1);

    return 0;
}
