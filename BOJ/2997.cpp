#include <bits/stdc++.h>

int main() {
    int t;
    std::vector<int> arr;
    
    for (int i = 0; i < 3; i++) {
        scanf("%d", &t);
        arr.push_back(t);
    }
    
    sort(arr.begin(), arr.end());
    
    if (arr[2] - arr[1] > arr[1] - arr[0])
        printf("%d", 2*arr[1] - arr[0]);
    else if (arr[2] - arr[1] < arr[1] - arr[0])
        printf("%d", 2*arr[1] - arr[2]);
    else
        printf("%d", 2*arr[2] - arr[1]);
    
    return 0;
}