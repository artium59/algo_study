#include <iostream>
#include <algorithm>
#include <tuple>
#include <vector>
using namespace std;

int n, k, a, b, c, d, cnt = 0;

int main() {
    vector<tuple<int, int, int, int>> vec(1000);

    scanf("%d %d", &n, &k);
    while (n--) {
        scanf("%d %d %d %d", &a, &b, &c, &d);
        // Gold, Silver, Bronze
        get<0>(vec[a-1]) = b;
        get<1>(vec[a-1]) = c;
        get<2>(vec[a-1]) = d;
    }
	
    b = get<0>(vec[k-1]); c = get<1>(vec[k-1]); d = get<2>(vec[k-1]);
    for_each(vec.begin(), vec.end(), [](const auto& a) {
        if (get<0>(a) > b) cnt++;
            else if (get<0>(a) == b) {
            if (get<1>(a) > c) cnt++;
            else if (get<1>(a) == c) {
                if (get<2>(a) > d) cnt++;
            }
        }
    });

    printf("%d", cnt+1);

    return 0;
}
