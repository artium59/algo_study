#include <iostream>


int main() {
    int testCase, studentNum, input, sum = 0, average = 0, up = 0;
    int grade[1000];
    float percent[1000];
    
    scanf("%d", &testCase);
    
    for (int a = 0; a < testCase; ++a) {
        // printf("Hello\n");
        scanf("%d", &studentNum);
        
        for (int b = 0; b < studentNum; ++b) {
            scanf("%d", &grade[b]);
            sum += grade[b];
        }
        
        average = sum / studentNum;
        
        for (int b = 0; b < studentNum; ++b) {
            if (average < grade[b])
                ++up;
        }

        percent[a] = ((float)up * 100) / (float)studentNum;
        sum = 0;
        up = 0;
    }
    
    for (int c = 0; c < testCase; ++c)
        printf("%.3f%%\n", percent[c]);
    
    return 0;
}