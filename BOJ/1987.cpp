#include <iostream>
#include <cstring>

int ans = 0;
bool visited[26];
short map[22][22];

int max(int a, int b) {
    return a > b ? a : b;
}

void Solve(int y, int x, int cnt) {
    if (map[y][x] == -1 || visited[map[y][x]]) {
        ans = max(ans, cnt); return;
    }

    visited[map[y][x]] = true;
    Solve(y-1, x, cnt+1);
    Solve(y+1, x, cnt+1);
    Solve(y, x-1, cnt+1);
    Solve(y, x+1, cnt+1);
    visited[map[y][x]] = false;
}

int main() {
    int r, c;
    char s;

    memset(map, -1, sizeof(map));
    memset(visited, false, sizeof(visited));

    scanf("%d %d", &r, &c);
    for (int i = 1; i <= r; i++) {
        for (int j = 1; j <= c; j++) {
            scanf(" %c", &s);
            map[i][j] = s - 'A';
        }
    }

    Solve(1, 1, 0);
    printf("%d", ans);

    return 0;
}