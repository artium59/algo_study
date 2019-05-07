#include <iostream>
#include <algorithm>

int n, k, t, arr[5000001];

int main() {
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    std::nth_element(arr, arr+k-1, arr+n);
    printf("%d", arr[k-1]);

    return 0;
}
