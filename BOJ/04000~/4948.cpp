#include <stdio.h>
#include <cstring>

bool isPrime[247000];

int main() {
    int n, cnt;
  
    memset(isPrime, true, sizeof(isPrime));
    isPrime[0] = isPrime[1] = false;
    for (int i = 2; i < 247000; i++) {
        if (isPrime[i]) {
            for (int j = i+i; j< 247000; j+=i)
                isPrime[j] = false;
        }
    }
  
    while (true) {
        scanf("%d", &n);
    
        if (n == 0) break;
    
        cnt = 0;
        for (int i = n; i < 2*n; i++)
            if (isPrime[i+1]) cnt++;
    
        printf("%d\n", cnt);
    }
  
    return 0;
}
