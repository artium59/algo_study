#include <cstdio>

inline int max(int a, int b) { return a > b ? a : b; }

const int yrr[4] = {1,-1,0,0}, xrr[4] = {0,0,1,-1};
int n, m, ans=0, ice[92][92];

int DFS(int b, int a) {
    if (!ice[b][a]) return 0;
    
    ice[b][a] = 0;
    int ret = max(max(DFS(b-1, a), DFS(b+1, a)), max(DFS(b, a-1), DFS(b,a+1))) + 1;
    ice[b][a] = 1;
    
    return ret;
}

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++)
            scanf("%d", &ice[i][j]);
    }
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (ice[i][j])
                ans = max(ans, DFS(i, j));
        }
    }

    printf("%d", ans);

    return 0;
}
