#include <iostream>
#include <algorithm>

int main() {
    int lines[4];
    
    for (int h = 0; h < 4; h++)
        scanf("%d", &lines[h]);
    
    std::sort(lines, lines + 4);
    
    printf("%d", lines[0] * lines[2]);
    
    return 0;
}
