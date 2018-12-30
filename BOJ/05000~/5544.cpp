#include <iostream>
#include <algorithm>
#include <vector>

int main() {
    int n, a, b, c, d, g = 1;
    std::vector<std::pair<int, int>> teams;
    scanf("%d", &n);
    std::vector<int> grades(n, 0);
    
    for (int h = 0; h < n; h++)
        teams.push_back(std::make_pair(0, h));
    
    for (int h = 0; h < n*(n-1)/2; h++) {
        scanf("%d %d %d %d", &a, &b, &c, &d);
        
        if (c != d)
            teams[c > d ? a-1 : b-1].first += 3;
        else {
            teams[a-1].first += 1;
            teams[b-1].first += 1;
        }
    }
    
    sort(teams.begin(), teams.end(), std::greater<std::pair<int, int>>());
    
    grades[teams[0].second] = g;
    for (int i = 1; i < n; i++) {
        g++;
        grades[teams[i].second] = (teams[i-1].first == teams[i].first) ? grades[teams[i-1].second] : g;
    }
    
    for (const auto& g : grades)
        printf("%d\n", g);
    
    return 0;
}
