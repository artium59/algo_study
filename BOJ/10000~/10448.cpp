#include <iostream>
#include <vector>

int t, k, ans;
bool two[1001];
std::vector<int> one(1, 1);

int main() {
    for (int i = 2; i < 45; i++)
        one.push_back(one.back()+i);

    for (const auto& o : one) {
        for (const auto& n : one) {
            if (o + n > 1000) break;
            two[o+n] = true;
        }
    }
	
    scanf("%d", &t);
    while (t--) {
        ans = 0;

        scanf("%d", &k);
        for (const auto& o : one) {
            if (k-o < 0) break;
            if (two[k-o]) { ans = 1; break; }
        }

        printf("%d\n", ans);
    }

    return 0;
}
