#include<bits/stdc++.h>

int main() {
    int arr[7], ans = 0, small=100;
    
    for (int i = 0; i < 7; i++) {
        scanf("%d", &arr[i]);
        if (arr[i] % 2 == 1) {
            ans += arr[i];
            if (small > arr[i]) small = arr[i];
        }
    }

    if (ans == 0)
        printf("-1");
    else
        printf("%d\n%d",ans,small);
    
    return 0;
}