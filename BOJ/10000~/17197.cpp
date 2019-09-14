#include <iostream>
#include <set>

inline int min(int a, int b) { return a < b ? a : b; }
inline int max(int a, int b) { return a > b ? a : b; }

const int MAX = 1e5;
int n, m, a, b, ans=5e8, parent[MAX+1], co[4][MAX+1];
std::set<int> checker;
std::pair<int, int> cow[MAX+1];

int Find(int a) {
    if (parent[a] == a) return a;
    else return parent[a] = Find(parent[a]);
}

void Union(int x, int y) {
    if (Find(x) != Find(y))
        parent[Find(x)] = Find(y);
}

int main() {
    for (int h = 0; h <= MAX; h++) {
        parent[h] = h;
        co[0][h] = co[1][h] = 2e8;
        co[2][h] = co[3][h] = -1;
    }
        
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &a, &b);
        cow[i].first = a; cow[i].second = b;
    }
    while (m--) {
        scanf("%d %d", &a, &b);
        Union(a-1, b-1);
    }

    for (int i = 0; i < n; i++) {
        a = Find(parent[i]);
        checker.insert(a);
        
        co[0][a] = min(co[0][a], cow[i].first);
        co[1][a] = min(co[1][a], cow[i].second);
        co[2][a] = max(co[2][a], cow[i].first);
        co[3][a] = max(co[3][a], cow[i].second);
    }
    
    for (const auto& c : checker)
        ans = min(ans, co[2][c]+co[3][c]-co[0][c]-co[1][c]);
    
    printf("%d", ans*2);

    return 0;
}
