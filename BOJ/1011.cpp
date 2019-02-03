#include <iostream>

int main() {
    int t;
    scanf("%d", &t);
    
    for (int h = 0; h < t; h++) {
        int x, y, ans = 0;
  
        scanf("%d %d", &x, &y);
        y = y-x; x = 0;
  
        for (int i = 1; ; i++) {
            y -= i; x += i;
            if (x >= y) {
                if (x - y < i) printf("%d\n", 2*i);
                else printf("%d\n", 2*i-1);
                break;
            }
        }
    }
    
    return 0;
}
