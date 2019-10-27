#include <iostream>
#include <cstring>
#include <queue>
#include <tuple>
using namespace std;

int n, w, dp[1002][1002];
pair<int, int> loc[1002];

inline int dist(pair<int, int> p, pair<int, int> q) {
    return abs(p.first - q.first) + abs(p.second - q.second);
}

int find(int a, int b) {
    if (a >= w || b >= w) return 0;

    int& ret = dp[a][b];
    if (ret != -1) return ret;

    int follow = (a > b ? a : b) + 1, a_move, b_move;

    if (a == 0) a_move = dist({1,1}, loc[follow]);
    else a_move = dist(loc[a], loc[follow]);

    if (b == 0) b_move = dist({n,n}, loc[follow]);
    else b_move = dist(loc[b], loc[follow]);

    ret = 1e9;
    ret = min(ret, min(find(follow, b)+a_move, find(a, follow)+b_move));

    return ret;
}

void route(int a, int b) {
    int follow = (a > b ? a : b) + 1, a_move, b_move;
    if (follow > w) return;

    if (a == 0) a_move = dist({ 1,1 }, loc[follow]);
    else a_move = dist(loc[a], loc[follow]);

    if (b == 0) b_move = dist({ n,n }, loc[follow]);
    else b_move = dist(loc[b], loc[follow]);

    if (dp[follow][b]+a_move > dp[a][follow]+b_move) {
        printf("2\n"); route(a, follow);
    }
    else {
        printf("1\n"); route(follow, b);
    }
}

int main() {
    scanf("%d %d", &n, &w);
    for (int i = 1; i <= w; i++)
        scanf("%d %d", &loc[i].first, &loc[i].second);

    memset(dp, -1, sizeof(dp));

    printf("%d\n", find(0, 0));
    route(0, 0);

    return 0;
}
