#include <bits/stdc++.h>

int main() {
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    
    printf("%d", std::max(c-b, b-a) - 1);
    
    return 0;
}