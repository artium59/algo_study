#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

int n, m, a, b, idx[100001];
vector<int> graph[100001];
vector<pair<int, int>> vec, tree;

inline pair<int, int> min(pair<int, int> p1, pair<int, int> p2) {
    return p1.first < p2.first ? p1 : p2;
}

pair<int, int> init(int node, int start, int end) {
    if (start >= end) return tree[node] = vec[start];
    return tree[node] = min(init(node*2, start, (start+end)/2), init(node*2+1, (start+end)/2+1, end));
}

pair<int, int> query(int node, int start, int end, int left, int right) {
    if (end < left || right < start) return { 1e9, 1e9 };
    if (left <= start && end <= right) return tree[node];

    return min(query(node*2, start, (start+end)/2, left, right),
                query(node*2+1, (start+end)/2+1, end, left, right));
}

void dfs(int height, int cur) {
    idx[cur] = vec.size();
    vec.push_back({ height, cur });

    for (const auto& g : graph[cur]) {
        if (g == 1 || idx[g] != 0) continue;
        dfs(height+1, g);
        vec.push_back({ height, cur });
    }
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n-1; ++i) {
        scanf("%d %d", &a, &b);
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    dfs(0, 1);

    tree.resize(vec.size()*4);
    init(1, 0, vec.size()-1);

    scanf("%d", &m);
    for (int i = 0; i < m; ++i) {
        scanf("%d %d", &a, &b);
        int l = min(idx[a], idx[b]);
        int r = max(idx[a], idx[b]);

        printf("%d\n", query(1, 0, vec.size()-1, l, r).second);
    }

    return 0;
}
