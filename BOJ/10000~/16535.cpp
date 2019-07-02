#include <iostream>

int n, b[501], dp[501][501];

int main(){
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
        scanf("%d",b+i);

    for(int i = n-1; i >= 0; i--){
        for(int k = i+1; k < n; k++){
            dp[i][k]=std::max(dp[i+1][k], dp[i+1][k-1]);
            for(int j = i+1; j <= k; j++){
                if(b[i]==b[j]) dp[i][k]=std::max(dp[i][k], 2+dp[i+1][j-1]+dp[j+1][k]);
            }
        }
    }

    printf("%d", dp[0][n-1]);

    return 0;
}
