#include <cstdio>
#include <algorithm>

int n, a, b;
char str[205];

int main() {
    scanf("%d %d %d", &n, &a, &b);
    for (int i = 0; i < n; ++i) scanf(" %c", str+i);
    std::reverse(str+a-1, str+b);
    for (int i = 0; i < n; ++i) printf("%c", str[i]);
    return 0;
}
