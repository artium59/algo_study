#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m, t, u, ans = 0;
    scanf("%d %d", &n, &m);
    vector<vector<int>> friends(n+1, vector<int>());
    vector<int> follow;
    bool isFriend[n+1];
    
    for (int g = 0; g < n+1; g++)
        isFriend[g] = false;
    
    for (int h = 0; h < m; h++) {
        scanf("%d %d", &t, &u);
        friends[t].push_back(u);
        friends[u].push_back(t);
    }
    
    t = 0;
    isFriend[1] = true;
    for (int j = 0; j < friends[1].size(); j++) {
        isFriend[friends[1][j]] = true;
        follow.push_back(friends[1][j]);
    }
    
    for (auto i : follow) {
        for (int j = 0; j < friends[i].size(); j++)
            isFriend[friends[i][j]] = true;
    }
    
    for (int k = 1; k < n+1; k++)
        if (isFriend[k])
            ans++;
    
    printf("%d", ans-1);
    
    return 0;
}