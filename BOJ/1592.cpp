#include <cstdio>

int people[1001], n, m, l, cur=1, ans;

int main() {
    scanf("%d %d %d", &n, &m, &l);

    people[1] = 1;
    while (people[cur] < m) {
        if (people[cur] % 2 != 0) {
            cur += l;
            if (cur > n) cur -= n;
            ++people[cur];
        }
        else {
            cur -= l;
            if (cur < 1) cur += n;
            ++people[cur];
        }

        ++ans;
    }

    printf("%d", ans);
    return 0;
}
