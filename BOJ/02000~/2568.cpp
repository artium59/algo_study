#include <cstdio>
#include <algorithm>
#include <queue>

const int MAX = 500001;
int a, b, n, line[MAX], arr[MAX], order[MAX];
std::queue<int> q;

int main(void) {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d %d", &a, &b);
        line[a] = b;
    }

    b = 0;
    for (int i = 1; i < MAX; ++i) {
        if (line[i] == 0) continue;

        if (b == 0) {
            order[i] = b;
            arr[b++] = line[i];
            continue;
        }

        a = std::lower_bound(arr, arr+b, line[i]) - arr;
        order[i] = a;
        arr[a] = line[i];

        if (a >= b) b++;
    }

    for (int i = MAX-1; i > 0 && b > 0; --i) {
        if (line[i] == 0 || order[i] != b-1) continue;
        line[i] = 0; --b;
    }

    for (int i = 1; i < MAX; ++i) {
        if (line[i] != 0)
            q.push(i);
    }

    printf("%d\n", q.size());
    while (!q.empty()) {
        printf("%d\n", q.front());
        q.pop();
    }

    return 0;
}
