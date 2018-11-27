#include <bits/stdc++.h>

int Reverse(int a) {
    int ret = 0;
    
    while (a) {
        ret = (ret * 10) + (a % 10);
        a = a / 10;
    }
    
    return ret;
}

int main() {
    int T, a, b;
    
    scanf("%d", &T);
    
    for (int t = 0; t < T; t++) {
        scanf("%d %d", &a, &b);
        printf("%d\n", Reverse(Reverse(a) + Reverse(b)));
    }
    
    return 0;
}