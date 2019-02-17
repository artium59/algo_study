#include <iostream>
#include <cstring>
#include <stack>

int trees[10001];

int main() {
    int t, n, a, b, ans;

    scanf("%d", &t);
    for (int h = 0; h < t; h++) {
        std::stack<int> arr, brr;

        memset(trees, -1, sizeof(trees));

        scanf("%d", &n);
        for (int i = 0; i < n-1; i++) {
            scanf("%d %d", &a, &b);
            trees[b] = a;
        }
        scanf("%d %d", &a, &b);

        while (a != -1) {
            arr.push(a);
            a = trees[a];
        }

        while (b != -1) {
            brr.push(b);
            b = trees[b];
        }

        while (!arr.empty() && !brr.empty()) {
            if (arr.top() == brr.top()) ans = arr.top();
            else break;
			
            arr.pop(); brr.pop();
        }

        printf("%d\n", ans);
    }

    return 0;
}