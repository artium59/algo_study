#include <bits/stdc++.h>

int main() {
    int n, t, num[10000];
    scanf("%d", &n);
    
    std::fill(num, num+10001, 0);
    
    for (int i = 0; i < n; i++) {
    	scanf("%d", &t);
    	num[t-1]++;
    }
    
    for (int i = 0; i < 10000; i++) {
    	for (int j = 0; j < num[i]; j++)
    		printf("%d\n", i+1);
    }
    
    return 0;
}
