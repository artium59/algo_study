#include <stdio.h>
#include <queue>

int main() {
    int n;
    std::queue<int> q;

    scanf("%d", &n);
    for (int i = 1; i <= n; i++) q.push(i);
    while (q.size() > 1) {
        q.pop();
        q.push(q.front());
        q.pop();
    }
    
    printf("%d", q.front());

    return 0;
}
