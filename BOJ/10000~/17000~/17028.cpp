#include <cstdio>

int main() {
    int n, i, arr[100];
    
    scanf("%d", &n);
    for (i = 0; i < n; i++) scanf("%d", arr+i);
    
    for (i = n-1; i > 0; i--) {
        if (arr[i] < arr[i-1]) break;
    }
    
    printf("%d", i);

    return 0;
}
