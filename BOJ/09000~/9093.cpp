#include <iostream>
#include <queue>

int t, l, r;
char str[1000];
std::queue<int> q;

int main() {
    scanf("%d ", &t);
    while (t--) {
        for (int i = 0; i < 1000; i++) {
            scanf("%c", &str[i]);
            if (str[i] == ' ') q.push(i);
            if (str[i] == '\n') { q.push(i); break; }
        }

        l = 0;
        while (!q.empty()) {
            r = q.front(); q.pop();
            for (int i = r-1; i >= l; i--)
                printf("%c", str[i]);
            if (!q.empty()) printf(" ");
            l = r+1;
        }
        printf("\n");
    }

    return 0;
}
