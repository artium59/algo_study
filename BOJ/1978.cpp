#include <bits/stdc++.h>

int main() {
    int n, t, ans = 0;
    std::vector<int> arr;
    scanf("%d", &n);
    
    for (int i = 0; i < n; i++) {
        scanf("%d", &t);
        arr.push_back(t);
    }
    
    // sort(arr.begin(), arr.end());
    
    for (int j = 0; j < n; j++) {
        for (int k = 2; k <= arr[n-1]; k++) {
            if (arr[j] % k == 0) {
                if (arr[j] == k) ans++;
                break;
            }
        }
    }
    
    printf("%d", ans);
    
    return 0;
}