#include <cstdio>

const int MAX = 1e6;
int j, a, ans;
char ch, jerseys[MAX+1];

int main() {
    scanf("%d %d", &j, &a);
    for (int i = 1; i <= j; i++) scanf(" %c", jerseys+i);
    while (a--) {
        scanf(" %c %d", &ch, &j);

        if (jerseys[j] == 'X') continue;

        if (ch == 'S') {
            ans++;
            jerseys[j] = 'X';
        }
        else if (ch == 'M') {
            if (jerseys[j] == 'S') continue;

            ans++;
            jerseys[j] = 'X';
        }
        else {
            if (jerseys[j] != 'L') continue;
            ans++;
            jerseys[j] = 'X';
        }
    }

    printf("%d", ans);

    return 0;
}
