#include <cstdio>
#include <algorithm>
#include <vector>

int n, c, m, a, b, ret, dwarf[300000];
std::vector<int> tree[1048576], tmp;

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
        tree[node].push_back(dwarf[start]);
        return;
    }

    divide(node*2, start, (start+end)/2);
    divide(node*2+1, (start+end)/2+1, end);

    merge(node);
}

void select(int node, int start, int end) {
    if (end < a || b < start) return;
    if (start >= end) {
        tmp.push_back(tree[node][0]);
        return;
    }

    if (a <= start && end <= b) {
        int k = (end - start) / 2;

        if (0 < k && tree[node][k] == tree[node][k-1])
            tmp.push_back(tree[node][k]);
        else if (k+1 < tree[node].size() && tree[node][k] == tree[node][k+1])
            tmp.push_back(tree[node][k]);

        return;
    }

    select(node*2, start, (start+end)/2);
    select(node*2+1, (start+end)/2+1, end);
}

int query(int node, int start, int end, int num) {
    if (end < a || b < start) return 0;

    if (a <= start && end <= b)
        return upper_bound(tree[node].begin(), tree[node].end(), num) -
               lower_bound(tree[node].begin(), tree[node].end(), num);

    return query(node*2, start, (start+end)/2, num) +
           query(node*2+1, (start+end)/2+1, end, num);
}

int main() {
    scanf("%d %d", &n, &c);
    for (int i = 0; i < n; ++i)
        scanf("%d", dwarf+i);
    divide(1, 0, n-1);

    scanf("%d", &m);
    while (m--) {
        ret = -1;
        tmp.clear();

        scanf("%d %d", &a, &b); --a; --b;
        select(1, 0, n-1);

        for (const int& t : tmp) {
            if (query(1, 0, n-1, t) > (b-a+1) / 2) {
                ret = t; break;
            }
        }

        if (ret == -1) printf("no\n");
        else printf("yes %d\n", ret);
    }

    return 0;
}
