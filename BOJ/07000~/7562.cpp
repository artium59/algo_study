#include <iostream>
#include <tuple>
#include <queue>
using namespace std;

const int xrr[8] = { -2, -1, 1, 2, -2, -1, 1, 2 };
const int yrr[8] = { -1, -2, -2, -1, 1, 2, 2, 1 };
int tc, l, x, y, distY, distX;
bool visited[300][300];

void Init() {
    for (int i = 0; i < 300; i++) {
        for (int j = 0; j < 300; j++)
            visited[i][j] = false;
    }
}

int BFS() {
    int i, j, ni, nj, cnt, ret = 0;
    queue<tuple<int, int, int>> q;

    Init();
    q.push(make_tuple(y, x, 0));
    while (!q.empty()) {
        i = get<0>(q.front());
        j = get<1>(q.front());
        cnt = get<2>(q.front());
        q.pop();
        
        if (i == distY && j == distX) {
            ret = cnt; break;
        }

        if (visited[i][j]) continue;
        visited[i][j] = true;

        for (int k = 0; k < 8; k++) {
            ni = i + yrr[k];
            nj = j + xrr[k];

            if (-1<ni&&ni<l && -1<nj&&nj<l && !visited[ni][nj])
                q.push(make_tuple(ni, nj, cnt+1));
        }
    }

    return ret;
} 

int main() {
    scanf("%d", &tc);
    for (int h = 0; h < tc; h++) {
        scanf("%d %d %d %d %d", &l, &y, &x, &distY, &distX);
        printf("%d\n", BFS());
    }

    return 0;
}
