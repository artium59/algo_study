#include <cstdio>
using namespace std;

const int MAX = 1000000;
int n, a, b, c, tree[2097152];

void update(int node, int start, int end, int loc, int num) {
    if (loc < start || end < loc) return;

    tree[node] += num;
    if (start >= end) return;

    update(node*2, start, (start+end)/2, loc, num);
    update(node*2+1, (start+end)/2+1, end, loc, num);
}

int query(int node, int start, int end, int cnt) {
    if (start >= end) return start;

    int mid = (start + end) / 2;
    if (tree[node*2] >= cnt) return query(node*2, start, mid, cnt);
    else return query(node*2+1, mid+1, end, cnt-tree[node*2]);
}

int main() {
    scanf("%d", &n);
    while (n--) {
        scanf("%d", &a);
        if (a == 1) {
            scanf("%d", &b);
            b = query(1, 0, MAX, b);
            printf("%d\n", b);
            update(1, 0, MAX, b, -1);
        }
        else {
            scanf("%d %d", &b, &c);
            update(1, 0, MAX, b, c);
        }
    }

    return 0;
}
