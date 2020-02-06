#include <cstdio>
#include <cstring>

inline int max(int a, int b) { return a > b ? a : b; }

struct T {
    int score=0, left=-1, right=-1;
};

int arr[10], ans;
bool occupy[45];
struct T tree[45];

int go(int start, int dist) {
    int next = start;

    for (int i = 0; i < dist; ++i) {
        if (next == 41) break;

        if (i == 0 && tree[next].right != -1) next = tree[next].right;
        else next = tree[next].left;
    }
    return next;
}

void dfs(int a, int b, int c, int d, int index, int sum) {
    if (index > 9) {
        ans = max(ans, sum);
        return;
    }

    occupy[41] = false;

    int next;
    if (a < 41) {
        next = go(a, arr[index]);

        if (!occupy[next]) {
            occupy[a] = false;
            occupy[next] = true;
            dfs(next, b, c, d, index+1, sum+tree[next].score);
            occupy[next] = false;
            occupy[a] = true;
        }
    }
    

    if (b < 41) {
        next = go(b, arr[index]);

        if (!occupy[next]) {
            occupy[b] = false;
            occupy[next] = true;
            dfs(a, next, c, d, index+1, sum+tree[next].score);
            occupy[next] = false;
            occupy[b] = true;
        }
    }

    if (c < 41) {
        next = go(c, arr[index]);

        if (!occupy[next]) {
            occupy[c] = false;
            occupy[next] = true;
            dfs(a, b, next, d, index+1, sum+tree[next].score);
            occupy[next] = false;
            occupy[c] = true;
        }
    }

    if (d < 41) {
        next = go(d, arr[index]);

        if (!occupy[next]) {
            occupy[d] = false;
            occupy[next] = true;
            dfs(a, b, c, next, index+1, sum+tree[next].score);
            occupy[next] = false;
            occupy[d] = true;
        }
    }
}

int main() {
    for (int i = 0; i < 10; ++i) scanf("%d", arr+i);
    
    for (int i = 1; i < 20; i++) {
        tree[i].score = 2*i;
        tree[i].left = i+1;
    }

    tree[0].left = 1;
    tree[5].right = 21;

    tree[21].score = 13;
    tree[21].left = 22;

    tree[22].score = 16;
    tree[22].left = 23;

    tree[23].score = 19;
    tree[23].left = 35;


    tree[10].right = 25;

    tree[25].score = 22;
    tree[25].left = 26;

    tree[26].score = 24;
    tree[26].left = 35;


    tree[15].right = 30;

    tree[30].score = 28;
    tree[30].left = 31;

    tree[31].score = 27;
    tree[31].left = 32;

    tree[32].score = 26;
    tree[32].left = 35;


    tree[35].score = 25;
    tree[35].left = 36;

    tree[36].score = 30;
    tree[36].left = 37;

    tree[37].score = 35;
    tree[37].left = 40;


    tree[19].left = 40;

    tree[40].score = 40;
    tree[40].left = 41;

    occupy[arr[0]] = true;
    dfs(0, 0, go(0, arr[0]), 0, 1, tree[go(0, arr[0])].score);
    printf("%d", ans);

    return 0;
}
