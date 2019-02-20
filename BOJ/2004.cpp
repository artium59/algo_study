#include <iostream>

int min(int a, int b) {
    return a < b ? a : b;
}

int two(int n) {
    if (n < 2) return 0;
    else return n/2 + two(n/2);
}

int five(int n) {
    if (n < 5) return 0;
    else return n/5 + five(n/5);
}

int main() {
    int n, m, f, t;
  
    scanf("%d %d", &n, &m);
  
    f = five(n) - (five(m) + five(n-m));
    t = two(n) - (two(m) + two(n-m));
  
    printf("%d ", min(t, f));
  
    return 0;
}
