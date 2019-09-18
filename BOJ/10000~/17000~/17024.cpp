#include <iostream>

int n, x, y, z=0, a[100001];

int main() {
    scanf("%d", &n);
    while (--n) {
        scanf("%d %d", &x, &y);
        
        a[x]++; a[y]++;
        z=std::max(z,std::max(a[x],a[y]));
    }
    
    printf("%d",z+1);
    
    return 0;
}
