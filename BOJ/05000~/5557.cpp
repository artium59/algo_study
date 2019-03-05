#include <iostream>
#include <cstring>
#include <vector>

long arr[100][21];
std::vector<int> vec;

void Solve(int num, int cnt) {
    for (int i = 0; i < 21; i++) {
        if (arr[cnt-1][i] > 0) {
            if (i-num > -1) arr[cnt][i-num] += arr[cnt-1][i];
            if (i+num < 21) arr[cnt][i+num] += arr[cnt-1][i];
        }
    }
}

int main() {
    int n, t;

    memset(arr, 0, sizeof(arr));

    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &t);
        if (i == 0) arr[0][t] = 1;
        vec.push_back(t);
    }

    for (int i = 1; i < n-1; i++)
        Solve(vec[i], i);

    printf("%ld", arr[n-2][t]);

    return 0;
}
