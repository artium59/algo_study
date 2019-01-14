#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct Computer {
    int start, end, cost;
    Computer(int s, int e, int c) : start(s), end(e), cost(c) {}
};

vector<int> roots(1001, 0);

bool operator<(Computer t, Computer u) {
    return t.cost > u.cost;
}

int Find(int a) {
    if (roots[a] == a) return a;
    else return roots[a] = Find(roots[a]);
}

void Union(int x, int y) {
    if (Find(x) != Find(y))
        roots[x] = Find(y);
}

int main() {
    int n, m, a, b, c, ans = 0;
    priority_queue<Computer> coms;
    
    for (int h = 0; h < 1001; h++)
        roots[h] = h;
    
    scanf("%d %d", &n, &m);
    for (int h = 0; h < m; h++) {
        scanf("%d %d %d", &a, &b, &c);
        coms.push(Computer(a, b, c));
    }
    
    while (!coms.empty()) {
        Computer top = coms.top();
        
        if (Find(top.start) != Find(top.end)) {
            Union(top.start, top.end);
            ans += top.cost;
        }
        
        coms.pop();
    }
    
    printf("%d", ans);
    
    return 0;
}
