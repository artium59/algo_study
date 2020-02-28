#include <cstdio>

int n, k, a, b, q, arr[100000], tree[262144];
char ch;

int init(int node, int start, int end) {
    if (start >= end) return tree[node] = arr[start];

    return tree[node] = init(node*2, start, (start+end)/2) *
                        init(node*2+1, (start+end)/2+1, end);
}

int update(int node, int start, int end, int loc, int num) {
    if (end < loc || loc < start) return tree[node];
    if (start >= end) return tree[node] = num;

    return tree[node] = update(node*2, start, (start+end)/2, loc, num) *
                        update(node*2+1, (start+end)/2+1, end, loc, num);
}

int query(int node, int start, int end, int left, int right) {
    if (right < start || end < left) return 1;
    if (left <= start && end <= right) return tree[node];

    return query(node*2, start, (start+end)/2, left, right) *
            query(node*2+1, (start+end)/2+1, end, left, right);
}

int main() {
    while (scanf("%d %d", &n, &k) != EOF) {
        for (int i = 0; i < n; ++i) {
            scanf("%d", arr+i);
            if (arr[i] > 0) arr[i] = 1;
            else if (arr[i] < 0) arr[i] = -1;
        }

        init(1, 0, n-1);

        for (int i = 0; i < k; ++i) {
            scanf(" %c %d %d", &ch, &a, &b);

            if (ch == 'C') {
                --a;

                if (b > 0) b = 1;
                else if (b < 0) b = -1;

                update(1, 0, n-1, a, b);
            }
            else {
                --a; --b;
                q = query(1, 0, n-1, a, b);

                if (q < 0) ch = '-';
                else if (q == 0) ch = '0';
                else ch = '+';

                printf("%c", ch);
            }
        }
        printf("\n");
    }

    return 0;
}
