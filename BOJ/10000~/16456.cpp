#include <bits/stdc++.h>

int main() {
    int n;
    std::vector<int> arr;
    scanf("%d", &n);
    
    arr.push_back(1);
    arr.push_back(1);
    arr.push_back(2);
    
    for (int i = 3; i < n; i++) {
        int t = arr[i-1] + arr[i-3];
        if (t > 1000000009)
            t -= 1000000009;
        arr.push_back(t);
    }
    
    printf("%d", arr[n-1]);
    
    return 0;
}