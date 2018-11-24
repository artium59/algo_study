#include <bits/stdc++.h>

int main() {
    int n, temp, i, sum = -1;
    std::vector<int> sides;
    
    scanf("%d", &n);
    for (int a = 0; a < n; a++) {
        scanf("%d", &temp);
        sides.push_back(temp);
    }
    
    sort(sides.begin(), sides.end(), std::greater<int>());
    
    for (i = 0; i < n-2; i++) {
        if (sides[i] < sides[i+1] + sides[i+2]) {
            sum = sides[i] + sides[i+1] + sides[i+2];
            break;
        }
    }
    
    printf("%d", sum);

    return 0;
}