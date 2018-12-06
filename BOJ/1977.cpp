#include <bits/stdc++.h>

int main() {
    int m, n, x, y, sum = 0;
    scanf("%d %d", &m, &n);
    
    x = ceil(sqrt(m));
    y = floor(sqrt(n));
    
    for (int a = x; a <= y; a++)
        sum += a * a;
    
    if (sum != 0)
        printf("%d\n%d", sum, x*x);
    else
        printf("-1");
    
    return 0;
}