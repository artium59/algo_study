#include <bits/stdc++.h>

int main() {
    int n, t;
    std::vector<int> arr;
    scanf("%d", &n);
    
    while (true) {
        scanf("%d", &t);
        if (t == 0) break;
        arr.push_back(t);
    }
    
    for (int i = 0; i < arr.size(); i++) {
        printf("%d is ", arr[i]);
        if (arr[i] % n != 0) printf("NOT ");
        printf("a multiple of %d.\n", n);
    }
    
    return 0;
}