#include <bits/stdc++.h>

int main() {
    int t;
    scanf("%d", &t);
    
    // 0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15
    //   1   2     3     4       5     6   7
    // 1ĭ 2ĭ  3ĭ   3ĭ    3ĭ     2ĭ  1ĭ
    for (int i = 0; i < t; i++) {
        long long x, y, j, ans;
        scanf("%lld %lld", &x, &y);

        y = y - x;
        x = 0;
        if (y == 1)
            ans = 1;
        else if (y == 2)
            ans = 2;
        else {
            for (j = 1; ; j++) {
                x += j;
                y -= j;
                if (x >= y) {
                    if (y - x <= -j)
                        ans = j * 2 - 1;
                    else
                        ans = j * 2;
                    break;
                }
            }
        }
        printf("%lld\n", ans);
    }
    
    return 0;
}