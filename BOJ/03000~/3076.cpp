#include <bits/stdc++.h>

int main() {
    int r, c, a, b;
    scanf("%d %d %d %d", &r, &c, &a, &b);
    
    for (int i = 0; i < r*a; i++) {
        for (int j = 0; j < c*b; j++) {
            if ((i/a)%2 == 0)
                printf("%c", ((j/b)%2 == 0) ? 'X' : '.');
            else
                printf("%c", ((j/b)%2 == 0) ? '.' : 'X');
        }
        printf("\n");
    }

    return 0;
}