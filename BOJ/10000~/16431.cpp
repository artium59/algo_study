#include <bits/stdc++.h>

using namespace std;

int main() {
    int bx, by, dx, dy, jx, jy, b, d;
    string ans;
    scanf("%d %d %d %d %d %d", &bx, &by, &dx, &dy, &jx, &jy);
    
    b = abs(bx-jx) > abs(by-jy) ? abs(bx-jx) : abs(by-jy);
    d = abs(dx-jx) + abs(dy-jy);
    
    if (b < d) ans = "bessie";
    else if (b == d) ans = "tie";
    else ans = "daisy";

    cout << ans;
    
    return 0;
}