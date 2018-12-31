#include <iostream>
#include <algorithm>

int main() {
    int height[9], sum = 0;

    for (int h = 0; h < 9; h++) {
        scanf("%d", &height[h]);
        sum += height[h];
    }

    for (int i = 0; i < 8; i++) {
        for (int j = i+1; j < 9; j++) {
            if (sum - height[i] - height[j] == 100) {
                height[i] = 0; height[j] = 0;
                break;
            }
        }
        if (height[i] == 0) break;
    }

    std::sort(height, height + 9);

    for (int i = 2; i < 9; i++)
        printf("%d\n", height[i]);

    return 0;
}
