#include <bits/stdc++.h>

int main() {
    int n, k;
    std::vector<int>arr, ans;
    
    scanf("%d %d", &n, &k);
    
    for (int i = 2; i <= n; i++)
        arr.push_back(i);
    
    while (arr.size() > 0) {
        int t = arr[0];
        
        for (int j = 0; j < arr.size(); j++) {    
            if (arr[j] % t == 0) {
                ans.push_back(arr[j]);
                arr.erase(arr.begin() + j);
                j--;
            }
        }
    }
    
    printf("%d", ans[k-1]);
    
    return 0;
}