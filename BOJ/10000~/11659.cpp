#include <iostream>
#include <vector>

int main() {
    int n, m, i, j, sum = 0;
    std::vector<int> arr(1, 0);
    
    scanf("%d %d", &n, &m);
    for (int h = 0; h < n; h++) {
        scanf("%d", &i);
        sum += i;
        arr.push_back(sum);
    }
    
    for (int h = 0; h < m; h++) {
        scanf("%d %d", &i, &j);
        printf("%d\n", arr[j] - arr[i-1]);
    }
    
    return 0;
}
