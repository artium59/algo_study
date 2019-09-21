#include <cstdio>

const int MAX=100000;
int t, g, p, ans=0, parent[MAX+1];

int Find(int x) {
    if (parent[x] == x) return x;
    else return parent[x] = Find(parent[x]);
}

void Union(int x, int y) {
    int fx = Find(x), fy = Find(y);
    
    if (fx != fy) parent[fx] = fy;
}

int main() {
    scanf("%d %d", &g, &p);
    for (int i = 1; i <= g; i++) parent[i] = i;
    
    for (int i = 0; i < p; i++) {
        scanf("%d", &t);
        
        g = Find(t);
        if (g != 0) ans++, Union(g, g-1);
        else break;
    }
    
    printf("%d", ans);

    return 0;
}
