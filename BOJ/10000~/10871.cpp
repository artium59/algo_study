#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, x, temp;
    vector<int> vec;
    
    scanf("%d %d", &n, &x);
    
    for (int a = 0; a < n; a++) {
        scanf("%d", &temp);
        vec.push_back(temp);
    }
    
    for (int b = 0; b < n; b++) {
        if (vec[b] < x)
            printf("%d ", vec[b]);
    }
    
    return 0;
}