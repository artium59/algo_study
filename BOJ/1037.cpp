#include <bits/stdc++.h>

int main() {
    int c, t;
    std::vector<int> arr;
    scanf("%d", &c);
    
    for (int i = 0; i < c; i++) {
        scanf("%d", &t);
        arr.push_back(t);
    }
    
    sort(arr.begin(), arr.end());
    printf("%d", arr[0] * arr[c-1]);
    
    return 0;
}