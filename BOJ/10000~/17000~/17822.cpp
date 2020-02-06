#include <iostream>
#include <cstring>
#include <queue>
#include <tuple>
using namespace std;

const int xrr[] {-1,1,0,0}, yrr[] {0,0,-1,1};
int n, m, t, x, d, k, sum=0, avg=0, erase_cnt=0;
bool xxx, visited[51][50];
deque<int> circle[51];
queue<pair<int, int>> q;

void rotate() {
    for (int i = x; i <= n; i+=x) {
        for (int j = 0; j < k; ++j) {
            if (d == 0) { // clock wise
                circle[i].push_front(circle[i].back());
                circle[i].pop_back();
            }
            else { // counter clock wise
                circle[i].push_back(circle[i].front());
                circle[i].pop_front();
            }
        }
    }
}

bool search(int a, int b, int c) {
    int x, y, dx, dy;
    bool check = false;

    memset(visited, false, sizeof(visited));
    visited[a][b] = true;

    q.push({ a, b });
    while (!q.empty()) {
        y = q.front().first;
        x = q.front().second;
        q.pop();

        for (int i = 0; i < 4; ++i) {
            dy = y+yrr[i]; dx = (x+xrr[i]+m)%m;

            if (0<dy&&dy<=n && !visited[dy][dx]) {
                visited[dy][dx] = true;

                if (c == circle[dy][dx]) {
                    circle[dy][dx] = -1;
                    q.push({ dy, dx });
                    ++erase_cnt;
                    check = true;
                }
            }
        }
    }

    return check;
}

bool erase() {
    xxx = false;
    avg = 0;

    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (circle[i][j] != -1) {
                if (search(i, j, circle[i][j])) {
                    circle[i][j] = -1;
                    ++erase_cnt;
                    xxx = true;
                }
                else
                    avg += circle[i][j];
            }
        }
    }

    return xxx;
}

void change() {
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (circle[i][j] < 0) continue;

            if (avg < circle[i][j]*(n*m-erase_cnt)) --circle[i][j];
            else if (avg > circle[i][j]*(n*m-erase_cnt)) ++circle[i][j];
        }
    }
}

int main() {
    scanf("%d %d %d", &n, &m, &t);
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j < m; ++j) {
            scanf("%d", &x);
            circle[i].push_back(x);
        }
    }
    for (int i = 0; i < t; ++i) {
        scanf("%d %d %d", &x, &d, &k);
        rotate();
        if (!erase()) change();
    }

    for (int i = 1; i <= n; ++i) {
        for (const auto& c : circle[i]) {
            if (c > 0) sum += c;
        }
    }

    printf("%d", sum);

    return 0;
}
