#define Q std::queue<std::pair<int, int>>

#include <stdio.h>
#include <cstring>
#include <queue>

short mapA[52][52], mapB[52][52];
int xrr[4] = { 1, -1, 0, 0 }, yrr[4] = { 0, 0, 1, -1 };
Q route, water;

int Find() {
    int x, y, ret;
    bool isAns = false;
  
    while (!route.empty()) {
        y = route.front().first;
        x = route.front().second;
        route.pop();
    
        for (int i = 0; i < 4; i++) {
            if ((mapB[y-yrr[i]][x-xrr[i]] > mapA[y][x] + 1) || mapB[y-yrr[i]][x-xrr[i]] == 0) {
                if (mapA[y-yrr[i]][x-xrr[i]] == 0) {
                    mapA[y-yrr[i]][x-xrr[i]] = mapA[y][x] + 1;
                    route.push(std::make_pair(y-yrr[i], x-xrr[i]));
                }
                else if (mapA[y-yrr[i]][x-xrr[i]] == 1000) {
                    ret = mapA[y][x]; isAns = true; break;
                }
            }
        }
    
        if (isAns) break;
    }
    if (!isAns) ret = -1;
  
    return ret;
}

void Flood() {
    int x, y;
  
    while (!water.empty()) {
        y = water.front().first;
        x = water.front().second;
        water.pop();
    
        for (int i = 0; i < 4; i++) {
            if (mapB[y-yrr[i]][x-xrr[i]] == 0) {
                mapB[y-yrr[i]][x-xrr[i]] = mapB[y][x] + 1;
                water.push(std::make_pair(y-yrr[i], x-xrr[i]));
            }
        }
    }
}

int main() {
    int r, c, ans;
    char ch;
  
    memset(mapA, -1, sizeof(mapA));
    memset(mapB, -1, sizeof(mapB));
  
    scanf("%d %d", &r, &c);
    for (int i = 1; i <= r; i++) {
        for (int j = 1; j <= c; j++) {
            scanf(" %c", &ch);
            if (ch == '*') {
                water.push(std::make_pair(i, j));
                mapA[i][j] = -1; mapB[i][j] = 1;
            }
            else if (ch == 'S') {
                route.push(std::make_pair(i, j));
                mapA[i][j] = 1; mapB[i][j] = 0;
            }
            else if (ch == 'D') {
                mapA[i][j] = 1000; mapB[i][j] = 10000;
            }
            else if (ch == 'X') {
                mapA[i][j] = -1; mapB[i][j] = -1;
            }
            else {
                mapA[i][j] = 0; mapB[i][j] = 0;
            }
        }
    }
  
    Flood();
    ans = Find();
  
    /* for (int i = 1; i <= r; i++) {
    for (int j = 1; j <= c; j++)
      printf("%4d ", mapA[i][j]);
    printf("\n");
    } */
  
    if (ans > 0) printf("%d", ans);
    else printf("KAKTUS");
  
    return 0;
}