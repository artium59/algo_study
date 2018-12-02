#include <bits/stdc++.h>

int main() {
    int n, t;
    std::vector<int> vec;
    scanf("%d", &n);
    
    for (int h = 0; h < n; h++) {
        scanf("%d", &t);
        vec.push_back(t);
    }
    
    sort(vec.begin(), vec.end());
    
    for (int i = 0; i < n; i++)
        printf("%d\n", vec[i]);
}