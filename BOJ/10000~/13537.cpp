#include <cstdio>
#include <algorithm>
#include <vector>

int n, m, i, j, k, arr[100000];
std::vector<int> tree[262145];

void merge(int node) {
    auto it1 = tree[node*2].begin(), it2 = tree[node*2+1].begin();

    while (it1 != tree[node*2].end() && it2 != tree[node*2+1].end()) {
        if (*it1 < *it2) tree[node].push_back(*it1), ++it1;
        else tree[node].push_back(*it2), ++it2;
    }

    for ( ; it1 != tree[node*2].end(); ++it1)
        tree[node].push_back(*it1);

    for ( ; it2 != tree[node*2+1].end(); ++it2)
        tree[node].push_back(*it2);
}

void divide(int node, int start, int end) {
    if (start >= end) {
        tree[node].push_back(arr[start]);
        return;
    }

    divide(node*2, start, (start+end)/2);
    divide(node*2+1, (start+end)/2+1, end);

    merge(node);
}

int search(int node, int num, int start, int end, int left, int right) {
    if (right < start || end < left) return 0;
    if (left <= start && end <= right)
        return tree[node].end() - upper_bound(tree[node].begin(), tree[node].end(), num);

    return search(node*2, num, start, (start+end)/2, left, right) +
            search(node*2+1, num, (start+end)/2+1, end, left, right);
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) scanf("%d", arr+i);
    divide(1, 0, n-1);

    scanf("%d", &m);
    while (m--) {
        scanf("%d %d %d", &i, &j, &k); --i; --j;
        printf("%d\n", search(1, k, 0, n-1, i, j));
    }

    return 0;
}
