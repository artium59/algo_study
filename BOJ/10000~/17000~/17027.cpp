#include <iostream>

int n, a, b, g, arr[4][4], ans[4]={0,0,0,0};

int main() {
    for (int i = 1; i < 4; i++) arr[i][i] = 1;
    
    scanf("%d", &n);
    while (n--) {
        scanf("%d %d %d", &a, &b, &g);
        
        for (int i = 1; i < 4; i++) {
            std::swap(arr[i][a], arr[i][b]);
            if (arr[i][g] == 1) ans[i]++;
        }
    }
    
    printf("%d", std::max(std::max(ans[1], ans[2]), ans[3]));

    return 0;
}
