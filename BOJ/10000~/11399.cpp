#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, t, ans = 0;
    vector<int> line;
    scanf("%d", &n);
    
    for (int i = 0; i < n; i++) {
        scanf("%d", &t);
        line.push_back(t);
    }
    
    sort(line.begin(), line.end());
    
    for (int j = 0; j < n; j++) {
        // ans += (line[j] * (n - j));
        ans += (line.back() * (j + 1));
        line.pop_back();
    }
    
    printf("%d", ans);
    
    return 0;
}