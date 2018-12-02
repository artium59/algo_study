#include <bits/stdc++.h>

bool isInCircle(int x, int y, int a, int b, int c) {
    if ((float)sqrt((x-a)*(x-a) + (y-b)*(y-b)) < c)
        return true;
    else
        return false;
}

int main() {
    int testCase;
    scanf("%d", &testCase);
    
    for (int i = 0; i < testCase; i++) {
        int startX, startY, endX, endY, planetCount, a, b, c, ans = 0;
        scanf("%d %d %d %d %d", &startX, &startY, &endX, &endY, &planetCount);
        
        for (int j = 0; j < planetCount; j++) {
            scanf("%d %d %d", &a, &b, &c);
            
            // if start 'and' end points is in circle -> false
            if (isInCircle(startX, startY, a, b, c) && isInCircle(endX, endY, a, b, c))
                continue;
            // else if start 'or' end points is in circle -> true
            else if (isInCircle(startX, startY, a, b, c) || isInCircle(endX, endY, a, b, c))
                ans++;
        }
        
        printf("%d\n", ans);
    }
    
    return 0;
}