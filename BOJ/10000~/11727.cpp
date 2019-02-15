#include <iostream>
#include <cstring>

const int MAX = 10007;

int cache[1001];

int max(int a, int b) {
    return a > b ? a : b;
}

int Tiling(int c) {
    if (c < 2) return 1;
    
    int& ret = cache[c];
    if (ret != -1) return ret;
    
    ret = max(ret, (Tiling(c-1) + 2*Tiling(c-2)) % MAX);
    
    return ret;
}

int main() {
    int n;
    scanf("%d", &n);
    
    memset(cache, -1, sizeof(cache));
    
    printf("%d", Tiling(n));
    
    return 0;
}
