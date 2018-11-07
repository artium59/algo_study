#include <bits/stdc++.h>

using namespace std;

int main() {
    int a;
    vector<int> vec;
    
    for (int i = 0; i < 3; i++) {
        scanf("%d", &a);
        vec.push_back(a);
    }
    
    sort(vec.begin(), vec.end());
    
    printf("%d", vec[1]);
    
    return 0;
}