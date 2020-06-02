#include <iostream>
#include <algorithm>
#include <tuple>
#include <vector>
using namespace std;
using ll = long long;

int n, m, a, b, c, d, arr[100000];
ll tree[262144], ans[100000];
vector<pair<int, int>> order;
vector<tuple<int, int, int, int>> queries;

ll init(int node, int start, int end) {
    if (start >= end) return tree[node] = arr[start];

    return tree[node] = init(node*2, start, (start+end)/2) +
                        init(node*2+1, (start+end)/2+1, end);
}

void update(int node, int start, int end, int loc, int num) {
    if (end < loc || loc < start) return;

    tree[node] += num;
    if (start >= end) return;

    update(node*2, start, (start+end)/2, loc, num);
    update(node*2+1, (start+end)/2+1, end, loc, num);
}

ll query(int node, int start, int end, int left, int right) {
    if (end < left || right < start) return 0;
    if (left <= start && end <= right) return tree[node];

    return query(node*2, start, (start+end)/2, left, right) +
            query(node*2+1, (start+end)/2+1, end, left, right);
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
        scanf("%d", arr+i);

    init(1, 0, n-1);
    scanf("%d", &m);
    while (m--) {
        scanf("%d", &a);
        if (a == 1) {
            scanf("%d %d", &b, &c);
            order.push_back({ b-1, c });
        }
        else {
            scanf("%d %d %d", &b, &c, &d);
            queries.push_back({ b, c-1, d-1, queries.size() });
        }
    }

    d = 0;
    sort(queries.begin(), queries.end());
    for (const auto& q : queries) {
        while (d < get<0>(q)) {
            update(1, 0, n-1, order[d].first, order[d].second-arr[order[d].first]);
            arr[order[d].first] = order[d].second;
            ++d;
        }

        ans[get<3>(q)] = query(1, 0, n-1, get<1>(q), get<2>(q));
    }

    for (int i = 0; i < queries.size(); ++i)
        printf("%lld\n", ans[i]);

    return 0;
}
