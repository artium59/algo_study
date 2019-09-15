#include <cstdio>
#include <queue>
using namespace std;

const int xrr[4] = { 1, -1, 0, 0 }, yrr[4] = { 0, 0, 1, -1 };
int n, nx, ny, x, y, area, perimeter, max_area=0, min_perimeter=987654321;
char ch;
bool ice[1002][1002], visited[1002][1002];
queue<pair<int, int>> q;

void BFS(int b, int a) {
    area = 1;
    perimeter = !ice[b+1][a] + !ice[b][a+1] + !ice[b-1][a] + !ice[b][a-1];
    q.push(make_pair(b, a));
    visited[b][a] = true;
    
    while (!q.empty()) {
        y = q.front().first;
        x = q.front().second;
        q.pop();
        
        for (int i = 0; i < 4; i++) {
            ny = y+yrr[i]; nx = x+xrr[i];
            if (0<ny&&ny<=n && 0<nx&&nx<=n && !visited[ny][nx] && ice[ny][nx]) {
                visited[ny][nx] = true; area++;
                perimeter += !ice[ny+1][nx] + !ice[ny][nx+1] + !ice[ny-1][nx] + !ice[ny][nx-1];
                q.push(make_pair(ny, nx));
            }
        }
    }
    
    if (max_area < area) {
        max_area = area; min_perimeter = perimeter;
    }
    else if (max_area == area) {
        if (perimeter < min_perimeter) min_perimeter = perimeter;
    }
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            scanf(" %c", &ch);
            ice[i][j] = ch == '#';
        }
    }
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (ice[i][j] && !visited[i][j]) BFS(i, j);
        }
    }
    
    printf("%d %d", max_area, min_perimeter);

    return 0;
}
