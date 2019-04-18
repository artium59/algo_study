#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>

int n, m, k, land[12][12], A[12][12], check[12][12];
std::deque<int> tree[12][12];

void SpringSummer(int y, int x) {
    int cur;
    bool swch = true;
    std::deque<int> dq;
    
    while (!tree[y][x].empty()) {
        cur = tree[y][x].front();
        tree[y][x].pop_front();
        
        if (land[y][x] >= cur && swch) {
            land[y][x] -= cur; cur++;
            if (cur%5 == 0) check[y][x]++;
            dq.push_back(cur);
        }
        else { // Summer
            swch = false;
            land[y][x] += cur/2;
        }
    }
    
    tree[y][x] = dq;
}

void Autumn(int y, int x) {
    for (int i = 0; i < check[y][x]; i++) {
        tree[y-1][x-1].push_front(1);  tree[y-1][x].push_front(1); tree[y-1][x+1].push_front(1);
        tree[y][x-1].push_front(1); tree[y][x+1].push_front(1);
        tree[y+1][x-1].push_front(1); tree[y+1][x].push_front(1); tree[y+1][x+1].push_front(1);
    }
    
    check[y][x] = 0;
}

void Winter() {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++)
            land[i][j] += A[i][j];
    }
}

int main() {
    int x, y, z, ans = 0;
    
    memset(check, 0, sizeof(check));
    for (int i = 1 ; i <= 10; i++)
        std::fill(land[i], land[i]+11, 5);
    
    scanf("%d %d %d", &n, &m, &k);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++)
            scanf("%d", &A[i][j]);
    }
    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", &x, &y, &z);
        tree[x][y].push_back(z);
    }
    
    for (int h = 0; h < k; h++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (!tree[i][j].empty()) SpringSummer(i, j);
            }
        }
        
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (check[i][j] > 0) Autumn(i, j);
            }
        }
        
        Winter();
    }
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++)
            ans += tree[i][j].size();
    }
    
    printf("%d", ans);
    
    return 0;
}
