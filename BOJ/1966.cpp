#include <iostream>
#include <queue>

using namespace std;

int main() {
    int t, n, m, p;
    scanf("%d", &t);

    for (int h = 0; h < t; h++) {
        int dest, count = 0;
        queue<pair<int, int>> prints;
        priority_queue<int> order;
        scanf("%d %d", &n, &m);
        
        for (int i = 0; i < n; i++) {
            scanf("%d", &p);
            prints.push(make_pair(p, i));
            order.push(p);
        }
        
        while (!order.empty()) {
            dest = order.top();
            count++;
            while (true) {
                if (dest == prints.front().first) {
                    if (m == prints.front().second)
                        goto Answer;
                    else {
                        prints.pop();
                        break;
                    }
                }
                else {
                    prints.push(prints.front());
                    prints.pop();
                }
            }
            order.pop();
        }
        
        Answer:
        printf("%d\n", count);
    }

    return 0;
}
