#include <iostream>
#include <queue>
#include <tuple>
using namespace std;

const int xrr[4] = { 1, -1, 0, 0 }, yrr[4] = { 0, 0, 1, -1 };
int n, m, a = -1, b, ans;
string arr[3000];

int BFS() {
    int x, y, nx, ny, dist, ret = -1;
    queue<tuple<int, int, int>> q;

    q.push(make_tuple(b, a, 0));
    while (!q.empty()) {
        y = get<0>(q.front());
        x = get<1>(q.front());
        dist = get<2>(q.front());
        q.pop();

        if (arr[y][x] > '2') {
            ret = dist; break;
        }

        if (arr[y][x] == '1') continue;
        arr[y][x] = '1';

        for (int i = 0; i < 4; i++) {
            ny = y + yrr[i];
            nx = x + xrr[i];

            if (-1<ny&&ny<n && -1<nx&&nx<m && arr[ny][nx] != '1')
                q.push(make_tuple(ny, nx, dist+1));
        }
    }

    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
		
        for (int j = 0; j < m && a == -1; j++) {
            if (arr[i][j] == '2') {
                b = i; a = j; break;
            }
        }
    }

    ans = BFS();

    if (ans == -1) cout << "NIE";
    else cout << "TAK\n" << ans;

    return 0;
}
