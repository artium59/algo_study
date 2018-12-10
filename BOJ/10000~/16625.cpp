// Only C++17

#include<bits/stdc++.h>

int main() {
    int p, q, s;
    scanf("%d %d %d", &p, &q, &s);
    
    printf((std::lcm(p,q) > s)? "no" : "yes");
    
    return 0;
}