#include <bits/stdc++.h>

int main(void) {
    long long a;
    int b, c, a1, a2, t = 0;
    std::vector<int> binary;
    scanf("%lld %d %d", &a, &b, &c);
    
    while (true) {
        if (b == 0) break;
        binary.push_back(b % 2);
        b /= 2;
    }
    
    a1 = a % c;
    for (int i = binary.size() - 1; i >= 0; i-- ) {
        if (i == binary.size() - 1) {
            a = a1;
        }
        else {
            if (binary[i] == 0) a = (a * a) % c;
            else a = (((a * a) % c) * a1) % c;
        }
    }
    
    printf("%lld", a);
    
    return 0;
}