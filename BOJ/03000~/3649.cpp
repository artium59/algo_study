#include <iostream>
#include <algorithm>

int x,n,a,b,lego[1000000];
bool check;

int main() {
    while (scanf("%d", &x) != EOF) {
        x *= 1e7; check = false;
        scanf("%d", &n);
        for (a = 0; a < n; a++) scanf("%d", lego+a);

        std::sort(lego, lego+n);
        for (a = 0; a < n; a++) {
            b = std::lower_bound(lego, lego+n, x-lego[a])-lego;
            if (a == b) b++;
            if (n <= b) continue;
            if (lego[a]+lego[b] == x) { check = true; break; }
        }

        if (check) printf("yes %d %d\n", lego[a], lego[b]);
        else printf("danger\n");
    }

    return 0;
}
