#include <bits/stdc++.h>

int main() {
    double a, b, c, s, S, R, r;
    scanf("%lf %lf %lf", &a, &b, &c);
    s = (a+b+c)/2;
    S = sqrt(s*(s-a)*(s-b)*(s-c));
    
    // 삼각형의 넓이 S
    printf("%.10lf\n", S);
    
    // 외접원의 반지름의 길이 R
    R = a*b*c/(4*S);
    printf("%.10lf\n", R);
    
    // 내접원의 반지름의 길이 r
    r = 2*S/(a+b+c);
    printf("%.10lf\n", r);
    
    // 외심과 내심 사이의 직선 거리
    if (a == b && b == c)
        printf("0\n");
    else
        printf("%.10lf\n", sqrt(R*(R-2*r)));
    
    // 외심에서 삼각형의 세 변에 내린 수선들의 길이의 합
    printf("%.10lf", sqrt(R*R-a*a/4)+sqrt(R*R-b*b/4)+sqrt(R*R-c*c/4));
    
    return 0;
}
