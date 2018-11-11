#define MAX 1000000 + 10

#include <bits/stdc++.h>

int main() {
    char t;
    std::vector<char> s;
    int change = 0;
    
    for (int a = 0; a < MAX; a++) {
        scanf("%c", &t);
        if (t == '\n')
            break;
        s.push_back(t);
    }
    
    for (int b = 0; b < s.size() - 1; b++) {
        if (s[b] != s[b + 1])
            change++;
    }
    
    printf("%d", (change % 2 == 0) ? change / 2 : (int)(change / 2) + 1);
    
    return 0;
}