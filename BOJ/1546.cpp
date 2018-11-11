#include <iostream>

int main() {
    int num, max = 1;
    float sum = 0, average;
    float score[1000];
    
    scanf("%d", &num);
    
    for (int a = 0; a < num; ++a) {
        scanf("%f", &score[a]);
        
        if (score[a] > max)
            max = score[a];
    }
    
    for (int b = 0; b < num; ++b) {
        score[b] = (float)(score[b] * 100) / (float)max;
    }
    
    for(int c = 0; c < num; ++c) {
        sum += score[c];
    }
    
    printf("%.2f", ((float)sum / (float)num));
    
    return 0;
}