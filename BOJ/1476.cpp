#include <stdio.h>

int main() {
    int a, b, c, x, y, z, ans;
    
    scanf("%d %d %d", &x, &y, &z);
    
    for (a = 1; ; a++) {
        if ((28*19*a) % 15 == 1) break;
    }
    for (b = 1; ; b++) {
        if ((15*19*b) % 28 == 1) break;
    }
    for (c = 1; ; c++) {
        if ((28*15*c) % 19 == 1) break;
    }

    ans = (x*28*19*a + y*15*19*b + z*15*28*c) % (15*28*19);
    if (ans == 0) ans = 15*28*19;
    
    printf("%d", ans);

    return 0;
}
