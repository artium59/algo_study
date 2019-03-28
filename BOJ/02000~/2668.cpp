#include <iostream>
#include <cstring>

int n, size = 0, arr[101];
bool visited[101], ans[101];

void DFS(int start, int cur) {
    if (cur == -1) return;
    
    if (visited[start]) {
        for (int i = 1; i <= n; i++) {
            if (visited[i]) {
                if (!ans[i]) size++;
                ans[i] = true;
            }
        }
        
        return;
    }
    
    if (visited[arr[cur]]) {
        memset(visited, false, sizeof(visited));
        return;
    }
    
    visited[arr[cur]] = true;
    DFS(start, arr[cur]);
}

int main() {
    memset(arr, -1, sizeof(arr));
    
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &arr[i]);
    }
    
    for (int i = 1; i <= n; i++)
        DFS(i, i);
    
    printf("%d\n", size);
    for (int i = 1; i <= n; i++)
        if (ans[i]) printf("%d\n", i);
    
    return 0;
}
