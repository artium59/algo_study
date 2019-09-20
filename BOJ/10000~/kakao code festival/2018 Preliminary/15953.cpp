#include <cstdio>

int main() {
    int t, a, b, ans, arr[6]={1,2,3,4,5,6}, brr[5]={1,2,4,8,16};
    int am[6]={500,300,200,50,30,10}, bm[5]={512,256,128,64,32};
    
    scanf("%d", &t);
    while (t--) {
        ans = 0;
        scanf("%d %d", &a, &b);
        
        for (int i = 0; a != 0 && i < 6; i++) {
            if (a <= arr[i]) { ans += am[i]; break;}
            a -= arr[i];
        }
        for (int i = 0; b != 0 && i < 5; i++) {
            if (b <= brr[i]) { ans += bm[i]; break;}
            b -= brr[i];
        }
        
        printf("%d\n", ans*10000);
    }

    return 0;
}
