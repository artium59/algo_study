#include <cstdio>
#include <algorithm>
#include <vector>

int n, m, k, t, loc;
bool is_used[4000000];
std::vector<int> cards;

int main() {
    scanf("%d %d %d", &n, &m, &k);
    while (m--) {
        scanf("%d", &t);
        cards.push_back(t);
    }
    sort(cards.begin(), cards.end());
    while (k--) {
        scanf("%d", &t);
        loc = lower_bound(cards.begin(), cards.end(), t+1) - cards.begin();

        while (is_used[loc]) ++loc;
        is_used[loc] = true;
        printf("%d\n", cards[loc]);
    }

    return 0;
}
