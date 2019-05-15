#include <cstdio>

int i,n,m,k,a=0;
bool c[1001];

int main() {
    scanf("%d %d",&n,&m);

    while(m--) {
        scanf("%d",&k);
        for(i = k; i <= n; i+=k)
            c[i]=true;
    }

    for(i = 0; i < 1001; i++)
        if(c[i])a+=i;

    printf("%d",a);
}
