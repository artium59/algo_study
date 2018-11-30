#include <bits/stdc++.h>

int main() {
    int t, c = 0;
    bool student[30] = {false, };
    
    for (int i = 0; i < 28; i++) {
        scanf("%d", &t);
        student[t-1] = 1;
    }
    
    for (int j = 0; j < 30; j++)
        if (!student[j])
            printf("%d\n", j+1);
    
    return 0;
}