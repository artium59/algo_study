#include <bits/stdc++.h>

using namespace std;

int main() {
    int a;
    int cut[5] = {90, 80, 70, 60, 0};
    char grade[5] = {'A', 'B', 'C', 'D', 'F'};
    
    scanf("%d", &a);
    
    for (int i = 0; i < 5; i++) {
        if (a >= cut[i]) {
            printf("%c", grade[i]);
            break;
        }
    }
    
    return 0;
}