#include <iostream>
#include <queue>

long long Find(int num) {
    long long cur = 1, ret;
    std::queue<long long> q;
    q.push(cur);

    while (!q.empty()) {
        cur = q.front();
        q.pop();

        if (cur % num == 0) {
            ret = cur; break;
        }

        q.push(cur*10);
        q.push(cur*10+1);
    }

    return ret;
}

int main() {
    int t;
    long long n;

    scanf("%d", &t);
    for (int i = 0; i < t; i++) {
        scanf("%lld", &n);
        printf("%lld\n", Find(n));
    }

    return 0;
}
