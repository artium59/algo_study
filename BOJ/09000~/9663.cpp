#include <iostream>
#include <cstring>

int n, ans = 0, chess[15];

int abs(int a) {
    return a > 0 ? a : -a;
}

bool Check(int a) {
    for (int i = 0; i < n; i++) {
        if (chess[i] == -1 || i == a) break;
        
        if (chess[i] == chess[a] || abs(i-a) == abs(chess[i]-chess[a]))
            return false;
    }
    
    return true;
}

void Solve(int a, int b) {
    chess[a] = b;
    
    if (!Check(a)) return;
    
    if (a+1 == n) {
        ans++; return;
    }
    for (int i = 0; i < n; i++)
        Solve(a+1, i);
}

int main() {
    scanf("%d", &n);
    
    for (int i = 0; i < n; i++) {
        memset(chess, -1, sizeof(chess));
        Solve(0, i);
    }
    
    printf("%d", ans);
    
    return 0;
}
