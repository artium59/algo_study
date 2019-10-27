#include <cstdio>

int n, ans[2], paper[129][129];

inline bool same(int v_start, int v_end, int h_start, int h_end, int color) {
    for (int i = v_start; i <= v_end; ++i) {
        for (int j = h_start; j <= h_end; ++j) {
            if (paper[i][j] != color) return false;
        }
    }

    return true;
}

void find(int v_start, int v_end, int h_start, int h_end) {
    if (v_start > v_end || h_start > h_end) return;

    if (same(v_start, v_end, h_start, h_end, paper[v_start][h_start])) {
        ++ans[paper[v_start][h_start]];
    }
    else {
        int half = (v_end-v_start+1)/2;

        find(v_start, v_start+half-1, h_start, h_start+half-1);
        find(v_start, v_start+half-1, h_start+half, h_end);
        find(v_start+half, v_end, h_start, h_start+half-1);
        find(v_start+half, v_end, h_start+half, h_end);
    }
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j)
            scanf("%d", &paper[i][j]);
    }

    find(1, n, 1, n);
    printf("%d\n%d", ans[0], ans[1]);

    return 0;
}
