#define ll long long

#include <iostream>
#include <queue>

std::priority_queue<ll> pq;

void Combine() {
    ll a, b;
    a = pq.top(); pq.pop();
    b = pq.top(); pq.pop();

    pq.push(a+b); pq.push(a+b);
}

int main() {
    int n, m;
    ll t;

    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &t);
        pq.push(-t);
    }

    for (int i = 0; i < m; i++)
        Combine();

    t = 0;
    while (!pq.empty()) {
        t += -pq.top();
        pq.pop();
    }

    printf("%lld", t);

    return 0;
}
