#include <iostream>
#include <stack>

int main() {
    int n, t;
    std::stack<std::pair<int, int>> towers;

    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &t);

        if (towers.empty()) printf("0 ");
        else {
            while (!towers.empty()) {
                if (towers.top().first > t) {
                    printf("%d ", towers.top().second);
                    break;
                }
                towers.pop();
            }

            if (towers.empty()) printf("0 "); 
        }
        towers.push(std::make_pair(t, i+1));
    }

    return 0;
}
