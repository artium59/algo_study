#include <bits/stdc++.h>

int main() {
    int n, m, t, i, j, ans = 0;
    std::vector<int> arr;
    scanf("%d %d", &n, &m);
    
    for (int h = 0; h < n; h++) {
        scanf("%d", &t);
        arr.push_back(t);
    }
    
    sort(arr.begin(), arr.end());
    
    i = 0; j = n - 1;
    
    while (true) {
        int sum = arr[i] + arr[j];
        
        if (sum > m)
            j--;
        else if (sum < m)
            i++;
        else {
            ans++;
            arr.erase(arr.begin() + i);
            arr.erase(arr.begin() + j - 1);
            j--;
        }
        
        if (i >= j || arr.size() < 2) break;
    }
    
    printf("%d", ans);
    
    return 0;
}