#include <iostream>

int main() {
    int n;
    scanf("%d", &n);

    for (int h = 0; h < n; h++) {
        std::string s;
        std::cin >> s;

        ((s[s.size()-1] - '0')%2 == 0) ? printf("even\n") : printf("odd\n");
    }

    return 0;
}
