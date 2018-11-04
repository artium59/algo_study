#define MEMBER 5

#include <iostream>

int main() {
    int sum = 0, scores[MEMBER];
    
    for (int m = 0; m < MEMBER; ++m) {
        scanf("%d", &scores[m]);
        
        if (scores[m] < 40)
            scores[m] = 40;
    }
    
    for (int n = 0; n < MEMBER; ++n) {
        sum += scores[n];
    }
    
    printf("%d\n", (sum / MEMBER));
    
    return 0;
}