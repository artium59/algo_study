#include <iostream>

const int MAX = 100001;
int count = 0, students[MAX], order[MAX], check[MAX] = {-1, };

void DFS(int start, int cur, int num) {
    if (check[cur] < 0) return;
    if (0 < check[cur] && check[cur] < start) return;

    if (check[cur] == start) {
        count += (num - order[cur]);
        return;
    }

    check[cur] = start;
    order[cur] = num;
    DFS(start, students[cur], num+1);
}

int main() {
    int t, n;

    scanf("%d", &t);
    for (int h = 0; h < t; h++) {
        count = 0;

        scanf("%d", &n);
        for (int i = 1; i <= n; i++) {
            check[i] = 0;
            scanf("%d", &students[i]);
            if (i == students[i]) {
                check[i] = -1; count++;
            }
        }

        for (int i = 1; i <= n; i++) {
            if (check[i] == 0) DFS(i, i, 1);
        }

        printf("%d\n", n-count);
    }

    return 0;
}
