#include <iostream>
#include <cstring>

int dp[1001][1001][2], cards[1001];

int max(int a, int b) { return a > b ? a : b; }
int min(int a, int b) { return a < b ? a : b; }

int Solve(int start, int end, bool myTurn) {
    int& ret = dp[start][end][myTurn];

    if (ret != 0) return ret;

    if (start >= end)
        return myTurn ? ret = cards[start] : ret = 0;

    if (myTurn)
        ret = max(Solve(start+1, end, !myTurn) + cards[start], Solve(start, end-1, !myTurn) + cards[end]);
    else
        ret = min(Solve(start+1, end, !myTurn), Solve(start, end-1, !myTurn));

    return ret;
}

int main() {
    int t, n;
    scanf("%d", &t);

    for (int h = 0; h < t; h++) {
        scanf("%d", &n);

        memset(dp, 0, sizeof(dp));
        memset(cards, 0, sizeof(cards));
        for (int i = 0; i < n; i++)
            scanf("%d", &cards[i]);

        printf("%d\n", Solve(0, n-1, true));
    }

    return 0;
}
