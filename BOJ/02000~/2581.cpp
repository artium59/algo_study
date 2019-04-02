#include <iostream>
#include <vector>
using namespace std;

int main() {
    int m, n, sum = 0;
    vector<int> vec;
    bool check[10001];

    for (int i = 0; i < 10001; i++)
        check[i] = true;
	
    check[0] = check[1] = false;
    for (int i = 2; i*i < 10001; i++) {
        if (check[i]) {
            for (int j = i+i; j < 10001; j+=i)
                check[j] = false;
        }
    }

    scanf("%d %d", &m, &n);
    for (int i = m; i <= n; i++) {
        if (check[i]) vec.push_back(i);
    }

    if (vec.empty()) printf("-1");
    else {
        for (const auto& v : vec) sum += v;
        printf("%d\n%d", sum, vec[0]);
    }

    return 0;
}
