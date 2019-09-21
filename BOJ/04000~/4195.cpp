#include <iostream>
#include <map>
using namespace std;

const int MAX=100000;
int t, n, cnt, parent[MAX], num[MAX];
string a, b;
map<string, int> names;

void Init() {
    cnt = 0;
    names.clear();
    for (int i = 0; i < MAX; i++) {
        parent[i] = i; num[i] = 1;
    }
}

int Find(int x) {
    if (parent[x] == x) return x;
    else return parent[x] = Find(parent[x]);
}

void Union(int x, int y) {
    int fx = Find(x), fy = Find(y);
    
    if (fx != fy) {
        parent[fy] = fx;
        num[fx] += num[fy];
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> t;
    while (t--) {
        Init();
        cin >> n;
        while (n--) {
            cin >> a >> b;
            
            if (names.find(a) == names.end())
                names.insert(make_pair(a, cnt)), cnt++;
            if (names.find(b) == names.end())
                names.insert(make_pair(b, cnt)), cnt++;
            
            Union(names[a], names[b]);
            
            cout << num[Find(names[a])] << "\n";
        }
    }

    return 0;
}
