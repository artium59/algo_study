#include <iostream>
#include <cmath>

int n, a;
long long once[501], twice[501], once_sum[501], twice_sum[501];
long double m, v, ans=998877665544.0;

int main() {
    scanf("%d %d", &n, &a);
    for (int i = 1; i <= n; i++) {
        scanf("%lld", once+i);
        twice[i] = once[i] * once[i];
        
        once_sum[i] = once[i] + once_sum[i-1];
        twice_sum[i] = twice[i] + twice_sum[i-1];
    }
    
    for (int i = 0; i <= n-a+1; i++) {
        for (int j = a; i+j <= n; j++) {
            m = (once_sum[i+j] - once_sum[i]) / (long double)j;
            v = (twice_sum[i+j] - twice_sum[i]) / (long double)j - m*m;
            v = sqrt(v);
            
            if (ans > v) ans = v;
        }
    }
    
    printf("%Lf", ans);

    return 0;
}
