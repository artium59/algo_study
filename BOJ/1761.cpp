#include <iostream>
#include <tuple>
#include <vector>
using namespace std;
using ll = long long;

int n, m, a, b, idx[40001];
ll c;
vector<pair<int, ll>> graph[40001];
vector<tuple<int, int, ll>> vec, tree;

inline tuple<int, int, ll> min_tuple(tuple<int, int, ll> t1, tuple<int, int, ll> t2) {
    return get<0>(t1) < get<0>(t2) ? t1 : t2;
}

void dfs(int height, int cur, ll dist) {
    idx[cur] = vec.size();
    vec.push_back({ height, cur, dist });

    for (const auto& g : graph[cur]) {
        if (g.first == 1 || idx[g.first] != 0) continue;
        dfs(height+1, g.first, dist+g.second);
        vec.push_back({ height, cur, dist });
    }
}

tuple<int, int, ll> init(int node, int start, int end) {
    if (start >= end) return tree[node] = vec[start];
    return tree[node] = min_tuple(init(node*2, start, (start+end)/2),
                                  init(node*2+1, (start+end)/2+1, end));
}

tuple<int, int, ll> query(int node, int start, int end, int left, int right) {
    if (right < start || end < left) return { 1e9, 1e9, 1e15 };
    if (left <= start && end <= right) return tree[node];

    return min_tuple(query(node*2, start, (start+end)/2, left, right),
                     query(node*2+1, (start+end)/2+1, end, left, right));
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n-1; ++i) {
        scanf("%d %d %lld", &a, &b, &c);
        graph[a].push_back({ b, c });
        graph[b].push_back({ a, c });
    }

    dfs(0, 1, 0LL);
    tree.resize(vec.size()*4);
    init(1, 0, vec.size()-1);

    scanf("%d", &m);
    while (m--) {
        scanf("%d %d", &a, &b);
        a = idx[a], b = idx[b];
        int l = min(a, b), r = max(a, b);

        auto t = query(1, 0, vec.size()-1, l, r);
        printf("%lld\n", abs(get<2>(vec[a]) - get<2>(t))+abs(get<2>(vec[b]) - get<2>(t)));
    }

    return 0;
}
