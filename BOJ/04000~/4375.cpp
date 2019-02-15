#include <iostream>

using namespace std;

int Answer(int n) {
    int ans = 1, count = 1;
    
    while (ans != 0) {
        ans = (ans*10+1) % n;
        count++;
    }
    
    return count;
}

int main() {
    int n;
    
    while(scanf("%d",&n) != EOF) {
        if (n == 1) printf("1\n");
        else printf("%d\n", Answer(n));
    }
    
    return 0;
}
