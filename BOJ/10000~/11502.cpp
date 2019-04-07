#include <iostream>
#include <vector>

int main() {
    int t = 0, k, arr[1001];
    bool p[1001];
    std::vector<int> one;
    std::vector<std::pair<int, int>> two;

    for (int i = 0; i < 1001; i++) {
        p[i] = true;
        arr[i] = -1;
    }

    p[0]= p[1] = false;
    for (int i = 2; i*i < 1001; i++) {
        if (p[i]) {
            for (int j = i+i; j < 1001; j+=i)
                p[j] = false;
        }
    }

    for (int i = 2; i < 1001; i++) {
        if (p[i]) one.push_back(i);
    }

    for (const auto& o : one) {
        for (const auto& n : one) {
            if (o + n > 1000) break;

            if (arr[o+n] == -1) {
                two.push_back(std::make_pair(o, n));
                arr[o+n] = t; t++;
            }
        }
    }

    scanf("%d", &t);
    while (t--) {
        scanf("%d", &k);

        for (const auto& o : one) {
            if (arr[k - o] != -1) {
                printf("%d %d %d\n", o, two[arr[k-o]].first, two[arr[k-o]].second);
                break;
            }
        }
    }

    return 0;
}
