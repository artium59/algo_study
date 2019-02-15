#include <iostream>

int rgb[2][3];

int min(int a, int b) {
    return a < b ? a : b;
}

int min(int a, int b, int c) {
    return min(a, min(b, c));
}

void Push() {
    for (int i = 0; i < 3; i++)
        rgb[0][i] = rgb[1][i];
}

int main() {
    int n;
    scanf("%d", &n);
    
    rgb[0][0] = 0; rgb[0][1] = 0; rgb[0][2] = 0;
    for (int i = 0; i < n; i++) {
        scanf("%d %d %d", &rgb[1][0], &rgb[1][1], &rgb[1][2]);
        
        rgb[1][0] += min(rgb[0][1], rgb[0][2]);
        rgb[1][1] += min(rgb[0][0], rgb[0][2]);
        rgb[1][2] += min(rgb[0][0], rgb[0][1]);
        
        Push();
    }
    
    printf("%d", min(rgb[0][0], rgb[0][1], rgb[0][2]));
    
    return 0;
}
