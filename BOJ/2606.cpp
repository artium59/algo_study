#include <iostream>
#include <cstring>
#include <vector>

int ans = 0;
bool isChosen[100];
std::vector<int> coms[100];

void DFS(int start) {
    if (isChosen[start]) return;
  
    isChosen[start] = true;
    for (const auto c : coms[start]) {
        if (!isChosen[c]) {
            ans++; DFS(c);
        }
    }
}

int main() {
    int n, m, a, b;
  
    memset(isChosen, false, sizeof(isChosen));
  
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &a, &b);
        coms[a-1].push_back(b-1);
        coms[b-1].push_back(a-1);
    }
  
    DFS(0);
    printf("%d", ans);
  
    return 0;
}
