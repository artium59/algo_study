#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>

bool apt[27][27];
std::vector<int> ans;

int DFS(int y, int x) {
    if (!apt[y][x]) return 0;
    apt[y][x] = false;
  
    int ret = DFS(y-1, x) + DFS(y+1, x) + DFS(y, x-1) + DFS(y, x+1) + 1;
  
    return ret;
}

int main() {
    int n;
    char c;
  
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            scanf(" %c", &c);
            apt[i][j] = c == '1' ? true : false;
        }
    }
  
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (apt[i][j]) ans.push_back(DFS(i, j));
        }
    }
  
    sort(ans.begin(), ans.end());
  
    printf("%d\n", ans.size());
    for (const auto& a : ans)
        printf("%d\n", a);

    return 0;
}
