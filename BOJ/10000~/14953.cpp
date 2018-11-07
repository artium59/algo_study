#define MAX 100010

#include <bits/stdc++.h>

using namespace std;

vector<int> roads[MAX];
vector<int> roadCount(MAX, 0);

bool Ascending(const int& a, const int& b) {
    return (roadCount[a] < roadCount[b]);
}

int main() {
    int n, m, y = 0, top = 0;
    cin >> n >> m;
    
    vector<int> orders(n, 0);
    vector<int> stores(n ,1);
    
    for (int z = 0; z < m; ++z) {
        int a, b;
        cin >> a >> b;
        
        roads[a].push_back(b);
        roads[b].push_back(a);
        
        ++roadCount[a];
        ++roadCount[b];
    }
    
    for (int c = 0; c < n; ++c) {
        orders[c] = c;
    }
    
    sort(orders.begin(), orders.end(), Ascending);
    
    for (int i = 0; i < n; ++i) {
        for (int j : roads[orders[i]]) {
            if (roadCount[orders[i]] < roadCount[j]) {
                stores[j] = max(stores[j], stores[orders[i]] + 1);
            }
        }
    }
    
    for (int k : stores) {
        top = max(top, k);
    }
    
    cout << top;
}