#include <cstdio>
#include <algorithm>
#include <vector>

int n, q, a, b, c, arr[100000];
std::vector<int> tree[263000];

template<typename T, typename U>
std::pair<T,U> operator+(const std::pair<T,U>& l, const std::pair<T,U>& r) {   
    return { l.first+r.first, l.second+r.second };
}

inline int min(int a, int b) { return a < b ? a : b; }

void merge(int node) {
    auto it1=tree[node*2].begin(), it2=tree[node*2+1].begin();

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

std::pair<int, int> search(int node, int num, int start, int end, int left, int right) {
    if (right < start || end < left) return { 0, 0 };

    if (left <= start && end <= right)
        return { lower_bound(tree[node].begin(), tree[node].end(), num) - tree[node].begin(),
                 upper_bound(tree[node].begin(), tree[node].end(), num) - tree[node].begin() };

    return search(node*2, num, start, (start+end)/2, left, right)
            + search(node*2+1, num, (start+end)/2+1, end, left, right);
}

int bst() {
    int l=-1e9 - 1, r=1e9 + 1, m;
    std::pair<int, int> ret;

    while (l <= r) {
        m = (l+r) / 2;

        ret = search(1, m, 0, n-1, a, b);
        if (ret.first == c-1 && ret.second == c) break;
        else ret.first < c ? l = m : r = m;
    }

    return m;
}

int main() {
    scanf("%d %d", &n, &q);
    for (int i = 0; i < n; ++i) scanf("%d", arr+i);
    divide(1, 0, n-1);

    while (q--) {
        scanf("%d %d %d", &a, &b, &c); --a; --b;
        printf("%d\n", bst());
    }

    return 0;
}
