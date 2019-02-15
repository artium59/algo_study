#include <iostream>

int tPower(int n) {
    int ret = 1;
    for (int i = 0; i < n; i++)
        ret *= 2;
    
    return ret;
}

int fPower(int n) {
    int ret = 1;
    for (int i = 0; i < n; i++)
        ret *= 4;
    
    return ret;
}

int Find(int n, int r, int c) {
    if (n == 0) return 0;
    
    int ret, t = tPower(n-1), f = fPower(n-1);
    
    if (t < r+1) {
        if (t < c+1) ret = 3*f + Find(n-1, r-t, c-t);
        else ret = 2*f + Find(n-1, r-t, c);
    }
    else {
        if (t < c+1) ret = f + Find(n-1, r, c-t);
        else ret = Find(n-1, r, c);
    }
    
    return ret;
}

int main() {
    int n, r, c;
    
    scanf("%d %d %d", &n, &r, &c);
    printf("%d", Find(n, r, c));
    
    return 0;
}
