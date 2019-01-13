#define MAX 1000000

#include <iostream>

int parent[MAX + 1];

int Find(int a) {
    if (parent[a] == a) return a;
    else return parent[a] = Find(parent[a]);
}

void Union(int x, int y) {
    if (Find(x) != Find(y))
        parent[Find(x)] = Find(y);
}

int main() {
    int n, m, a, b, c;
    scanf("%d %d", &n, &m);
    
    for (int h = 0; h <= MAX; h++)
        parent[h] = h;
    
    for (int h = 0; h < m; h++) {
        scanf("%d %d %d", &a, &b, &c);
        
        if (a == 0)
            Union(b, c);
        else
            printf(Find(b) == Find(c) ? "YES\n" : "NO\n");
    }
    
    return 0;
}
