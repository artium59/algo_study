#include <iostream>
#include <queue>
using namespace std;

const int yrr[] {-1,1,0,0}, xrr[] {0,0,-1,1};
int ans, y, x, dy, dx;
char student[5][5];
bool visited[25];

bool connect(int k) {
    int cnt = 1;
    bool check[25];
    queue<pair<int, int>> q;

    for (int i = 0; i < 25; ++i)
        check[i] = false;

    check[k] = true;
    q.push({ k/5, k%5 });
    while (!q.empty()) {
        y = q.front().first;
        x = q.front().second;
        q.pop();

        for (int i = 0; i < 4; ++i) {
            dy = y + yrr[i];
            dx = x + xrr[i];

            if (0<=dy&&dy<5 && 0<=dx&&dx<5) {
                if (check[dy*5+dx]) continue;
                check[dy*5+dx] = true;

                if (visited[dy*5+dx]) {
                    ++cnt;
                    q.push({ dy, dx });
                }
            }
        }
    }

    return cnt == 7;
}

void find(int idx, int cnt, int s) {
    if (cnt == 7) {
        if (s > 3 && connect(idx)) ++ans;
        return;
    }

    for (int i = idx+1; i < 25; ++i) {
        visited[i] = true;
        find(i, cnt+1, s+(student[i/5][i%5]=='S'));
        visited[i] = false;
    }
}

int main(void) {
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j)
            scanf(" %c", &student[i][j]);
    }

    for (int i = 0; i <= 18; ++i) {
        visited[i] = true;
        find(i, 1, student[i/5][i%5]=='S');
        visited[i] = false;
    }

    printf("%d", ans);
    return 0;
}
