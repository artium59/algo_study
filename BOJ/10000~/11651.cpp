#include <bits/stdc++.h>

using namespace std;

bool Compare(pair<int, int> a, pair<int, int> b) {
    if (a.second == b.second)
        return  a.first < b.first;
    else
        return a.second < b.second;
}

int main() {
    int x, y, n;
    vector<pair<int, int>> coordinate;
    scanf("%d", &n);
    
    for (int h = 0; h < n; h++) {
        scanf("%d %d", &x, &y);
        coordinate.push_back(pair<int, int>(x, y));
    }
    
    sort(coordinate.begin(), coordinate.end(), Compare);
    
    for (int i = 0; i < n; i++)
        printf("%d %d\n", coordinate[i].first, coordinate[i].second);
    
    return 0;
}