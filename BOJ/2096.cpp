#include <iostream>
#include <cmath>

int main() {
    int n, a, b, c, big[2][3], small[2][3];
    scanf("%d", &n);

    big[0][0] = 0; big[0][1] = 0; big[0][2] = 0;
    small[0][0] = 0; small[0][1] = 0; small[0][2] = 0;
    
    for (int i = 0; i < n; i++) {
        scanf("%d %d %d", &a, &b, &c);

        big[1][0] = std::max(big[0][0], big[0][1]) + a;
        big[1][1] = std::max(big[0][2], std::max(big[0][0], big[0][1])) + b;
        big[1][2] = std::max(big[0][1], big[0][2]) + c;

        small[1][0] = std::min(small[0][0], small[0][1]) + a;
        small[1][1] = std::min(small[0][2], std::min(small[0][0], small[0][1])) + b;
        small[1][2] = std::min(small[0][1], small[0][2]) + c;

        for (int j = 0; j < 3; j++) {
            big[0][j] = big[1][j];
            small[0][j] = small[1][j];
        }
    }

    printf("%d %d", std::max(big[0][0], std::max(big[0][1], big[0][2])), std::min(small[0][2], std::min(small[0][0], small[0][1])));

    return 0;
}
