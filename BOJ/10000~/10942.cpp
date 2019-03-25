#include <iostream>

int arr[2000];
bool dp[2000][2000];

int main() {
    int n, m, s, e;

    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    for (int i = n-1; i >= 0; i--) {
        for (int j = i; j < n; j++) {
            if (i == j) dp[i][j] = true;
            else if (j-i == 1) dp[i][j] = (arr[i] == arr[j]);
            else dp[i][j] = ((arr[i] == arr[j]) && dp[i+1][j-1]);
        }
    }

    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &s, &e);
        printf(dp[s-1][e-1] ? "1\n" : "0\n");
    }

    return 0;
}
