#include <iostream>
#include <stack>

int main() {
    int n, a, b, dna[4][4] = { {0, 2, 0, 1}, {2, 1, 3, 0}, {0, 3, 2, 1}, {1, 0, 1, 3} };
    char c;
    std::stack<int> dnaStack;
    
    scanf("%d ", &n);
    for (int i = 0; i < n; i++) {
        scanf("%c", &c);
        if (c == 'A') dnaStack.push(0);
        else if (c == 'G') dnaStack.push(1);
        else if (c == 'C') dnaStack.push(2);
        else dnaStack.push(3);
    }
    
    b = dnaStack.top();
    dnaStack.pop();
    while (!dnaStack.empty()) {    
        a = dnaStack.top();
        dnaStack.pop();
        b = dna[b][a];
    }
    
    if (b == 0) printf("A");
    else if (b == 1) printf("G");
    else if (b == 2) printf("C");
    else printf("T");
    
    return 0;
}
