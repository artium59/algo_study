#define V std::vector<std::pair<int, int>>

#include <stdio.h>
#include <cstring>
#include <vector>

int n, size, w = 0, b = 0;
bool left[20], right[20];
V black, white;

int max(int a, int b) {
    return a > b ? a : b;
}

void Solve(const V& chess, int s, int cnt, bool isWhite) {
    int y = chess[s].first, x = chess[s].second;
    int l = x+y, r = x-y+n-1;
    int ny, nx, nl, nr;
  
    if (left[l] || right[r]) return;
  
    if (isWhite) w = max(w, cnt);
    else b = max(b, cnt);

    left[l] = true;
    right[r] = true;
  
    for (int i = s+1; i < size; i++) {
        ny = chess[i].first; nx = chess[i].second;
        nl = nx+ny; nr = nx-ny+n-1;
    
        if (!left[nl] && !right[nr]) Solve(chess, i, cnt+1, isWhite);
    }
  
    left[l] = false;
    right[r] = false;
}

int main() {
    int k;

    memset(left, false, sizeof(left));
    memset(right, false, sizeof(right));
  
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &k);
            if (k == 1) {
                if ((i+j)%2 == 0) white.push_back(std::make_pair(i, j));
                else black.push_back(std::make_pair(i, j));
            }
        }
    }
  
    size = white.size();
    for (int i = 0; i < size; i++)
        Solve(white, i, 1, true);
  
    size = black.size();
    for (int i = 0; i < size; i++)
        Solve(black, i, 1, false);
    
    printf("%d", b+w);
  
    return 0;
}
