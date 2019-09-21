#include <cstdio>
#include <algorithm>

int n, m, x, y, z, xloc, yloc, cnt, year[50005], rain[50005];
bool swch;

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d %d", year+i, rain+i);

    scanf("%d", &m);
    while (m--) {
        scanf("%d %d", &y, &x);

        swch = true; cnt = 0;
        xloc = std::lower_bound(year, year + n, x) - year;
        yloc = std::lower_bound(year, year + n, y) - year;

        if (year[xloc] == x && year[yloc] == y) {
            swch = rain[xloc] <= rain[yloc];

            for (z = yloc+1; z < xloc && swch; z++) {
                cnt++;
                if (rain[z] < rain[xloc]) continue;
                swch = false;
            }

            if (swch) printf(cnt == x - y - 1 ? "true\n" : "maybe\n");
            else printf("false\n");
        }
        else if (year[xloc] == x && year[yloc] != y) {
            for (z = yloc; z < xloc; z++) {
                if (rain[z] < rain[xloc]) continue;
                swch = false; break;
            }

            printf(swch ? "maybe\n" : "false\n");
        }
        else if (year[xloc] != x && year[yloc] == y) {
            for (z = yloc+1; z < xloc; z++) {
                if (rain[z] < rain[yloc]) continue;
                swch = false; break;
            }

            printf(swch ? "maybe\n" : "false\n");
        }
        else {
            printf("maybe\n");
        }
    }

    return 0;
}
