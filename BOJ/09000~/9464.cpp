#include <iostream>
#include <algorithm>
#include <vector>

int gcd(int a, int b) { 
    if (b == 0) return a; 
    return gcd(b, a % b);  
} 

int main() {
    int tc, l, ans;
    std::vector<int> arr;

    for (int x = 2; x < 710; x++) {
        for (int y = 1; y < x; y++) {
            if ((x-y)%2 == 1 && gcd(x, y) == 1)
                arr.push_back(2*(2*x*y + x*x-y*y));
        }
    }

    sort(arr.begin(), arr.end());

    scanf("%d", &tc);
    for (int h = 0; h < tc; h++) {
        scanf("%d", &l);

        for (ans = 0; ans < arr.size(); ans++) {
            if (l-arr[ans] < 0) break;
            l -= arr[ans];
        }

        printf("%d\n", ans);
    }

    return 0;
}
