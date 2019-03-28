#include <bits/stdc++.h>

int arr[4];

void Swap() {
    int t = arr[0];
    arr[0] = arr[2]; arr[2] = arr[3];
    arr[3] = arr[1]; arr[1] = t;
}

int main() {
    int ans;
    double sum = -1, f;
    
    for (int i = 0; i < 4; i++)
        scanf("%d", &arr[i]);
    
    for (int j = 0; j < 4; j++) {
        f = (double)arr[0]/(double)arr[2] + (double)arr[1]/(double)arr[3];
        
        if (f > sum) {
            sum = f; ans = j;
            printf("%.2f %d\n", sum, ans);
        }
        Swap();
    }
    
    printf("%d", ans);
    
    return 0;
}