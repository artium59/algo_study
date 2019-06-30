#include <cstdio>
#include <algorithm>
#include <tuple>
#include <vector>
using namespace std;

int n, m, a, b;
char c;
vector<tuple<int, int, char>> key;

int main() {
    scanf("%d %d", &n, &m);
    while (m--) {
        scanf("%d %d %c", &a, &b, &c);
        key.push_back(make_tuple(b, a, c));
    }

    sort(key.begin(), key.end());
    for_each(key.begin(), key.end(), [](const auto& k) { printf("%c", get<2>(k)); });

    return 0;
}
