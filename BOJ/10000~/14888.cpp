#include <iostream>

inline int max(int a, int b) { return a > b ? a : b; }
inline int min(int a, int b) { return a < b ? a : b; }

const int MAX = 1000000001;
int n, arr[12], op[4], big = -MAX, small = MAX;

void Find(int cur, int j, int plus, int minus, int multiply, int divide) {
    if (j == n) {
        big = max(big, cur); small = min(small, cur);
        return;
    }

    if (plus > 0) Find(cur+arr[j], j+1, plus-1, minus, multiply, divide);
    if (minus > 0) Find(cur-arr[j], j+1, plus, minus-1, multiply, divide);
    if (multiply > 0) Find(cur*arr[j], j+1, plus, minus, multiply-1, divide);
    if (divide > 0) Find(cur/arr[j], j+1, plus, minus, multiply, divide-1);
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    for (int i = 0; i < 4; i++)
        scanf("%d", &op[i]);

    Find(arr[0], 1, op[0], op[1], op[2], op[3]);

    printf("%d\n%d", big, small);

    return 0;
}
