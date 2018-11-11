#include <bits/stdc++.h>

using namespace std;

int main() {
    int x, y, sum = 0;
    int month[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    string day[7] = {"SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT"};
    
    scanf("%d %d", &x, &y);
    
    for (int a = 0; a < x - 1; a++) {
        sum += month[a];
    }
    
    sum += y;
    
    printf("%s", day[sum % 7].c_str());
    
    return 0;
}