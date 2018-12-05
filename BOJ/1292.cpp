#include <bits/stdc++.h>

int main() {
    int ans = 0, start, end;
    std::vector<int> arr;
    
    for (int h = 1; h < 500; h++) {
        for (int i = 0; i < h; i++)
            arr.push_back(h);
    }
    
    scanf("%d %d", &start, &end);
    
    for (int j = start-1; j < end; j++)
        ans += arr[j];
    
    printf("%d", ans);
    
    return 0;
}