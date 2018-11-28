#include <bits/stdc++.h>

int main() {
    float n, d;
    scanf("%f %f", &n, &d);
    printf("%.1f", floor((n/2.0-d+0.05)*10)/10);
    return 0;
}