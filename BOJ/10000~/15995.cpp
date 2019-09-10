#include <stdio.h>

int main() {
    int a, x=1, m;
    
    scanf("%d %d", &a, &m);
    while (true) {
        if ((a*x) % m == 1) break;
        x++;
    }
    
    printf("%d", x);

    return 0;
}
