#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m = 0;
    //              0  1  2  3  4  5  6  7  8
    int count[9] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
    scanf("%d", &n);
    
    if (n == 0)
        m = 1;
    else {
        while (n > 0) {
            if (n % 10 == 9)
                count[6] += 1;
            else
                count[n % 10] += 1;

            n /= 10;
        }
    }
    
    if (count[6] % 2 == 0)
        count[6] /= 2;
    else
        count[6] = (int)(count[6] / 2) + 1;
    
    for (int i = 0; i < 9; i++) {
        m = max(m, count[i]);
    }
    
    printf("%d", m);
    
    return 0;
}