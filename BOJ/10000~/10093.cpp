#include <iostream>

int main() {
    long long a, b, t;
    
    scanf("%lld %lld", &a, &b);
    if (a > b) { t=a; a=b; b=t; }
    
    printf("%lld\n", std::max(b-a-1, 0LL)); a++;
    for ( ; a < b; a++) printf("%lld ", a);

    return 0;
}
