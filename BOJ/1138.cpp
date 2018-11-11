#include <bits/stdc++.h>

int main() {
    int n, t, count = 0;
    scanf("%d", &n);
    std::vector<int> input, line(n);
    
    for (int a = 0; a < n; a++) {
        scanf("%d", &t);
        input.push_back(t);
    }
    
    for (int b = n - 1; b > - 1; b--) {
        line.insert(line.begin() + input[b], b + 1);
    }
    
    for (int d = 0; d < line.size(); d++) {
        if (line[d] != 0)
            printf("%d ", line[d]);
    }
    
    return 0;
}