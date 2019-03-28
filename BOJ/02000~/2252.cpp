#include <iostream>
#include <queue>
#include <vector>

using namespace std;

queue<int> ans;
vector<vector<int>> graph;
vector<int> count;

void TopologicalSort(int n) {
    int person;
    
    for (int i = 0; i < n; i++) {
        if (count[i] == 0)
            ans.push(i);
    }
    
    for (int i = 0; i < n; i++) {
        person = ans.front();
        ans.pop();
        cout << person + 1 << " ";
        
        for (const auto& g : graph[person]) {
            count[g-1]--;
            if (count[g-1] == 0)
                ans.push(g-1);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, m, a, b;
    
    cin >> n >> m;
    
    for (int i = 0; i < n; i++) {
        graph.push_back(vector<int>());
        count.push_back(0);
    }
    
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        graph[a-1].push_back(b);
        count[b-1]++;
    }
    
    TopologicalSort(n);
    
    return 0;
}
