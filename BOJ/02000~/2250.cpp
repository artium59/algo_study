#include <iostream>
#include <cstring>
#include <queue>

int cnt = 1, ans, size = 0;
bool isRoot[10000];

struct NODE {
    int left, right, order;
};

struct NODE tree[10000];

void InOrder(int a) {
    if (a == -2) return;
  
    InOrder(tree[a].left);
    tree[a].order = cnt; cnt++;
    // printf("(%d %d) ", a, tree[a].order);
    InOrder(tree[a].right);
}

std::queue<int> BFS(std::queue<int> q) {
    int node, start = 987654321, end = 0;
    std::queue<int> ret;
    
    while (!q.empty()) {
        node = q.front();
        q.pop();
        
        if (start > tree[node].order) start = tree[node].order;
        if (end < tree[node].order) end = tree[node].order;
        
        if (tree[node].left != -2) ret.push(tree[node].left);
        if (tree[node].right != -2) ret.push(tree[node].right);
    }
    
    if (size < end-start+1) {
        ans = cnt; size = end-start+1;
    }
    
    return ret;
}

int main() {
    int n, r, a, b;
    std::queue<int> q;
    
    memset(isRoot, true, sizeof(isRoot));
    
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d %d", &r, &a, &b);
        tree[r-1].left = a-1;
        tree[r-1].right = b-1;
        isRoot[a-1] = isRoot[b-1] = false;
    }
    
    for (int i = 0; i < n; i++) {
        if (isRoot[i]) { r = i; break; }
    }
    
    InOrder(r);
    
    cnt = 1;
    q.push(r);
    while (!q.empty()) {
        q = BFS(q); cnt++;
    }
    
    printf("%d %d", ans, size);
    
    return 0;
}
