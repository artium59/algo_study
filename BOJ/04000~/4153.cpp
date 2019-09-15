#include <cstdio>

int main() {
    int a, b, c, t;

    while (true) {
        scanf("%d %d %d", &a, &b, &c);
        if (a+b+c == 0) break;
        
        if (a > b) { t=a; a=b; b=t; }
        if (b > c) { t=b; b=c; c=t; }
        
        printf(c*c-(a*a+b*b) ? "wrong\n" : "right\n");
    }

    return 0;
}
