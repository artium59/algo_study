#include <bits/stdc++.h>

int main() {
    double a, b, c, s, S, R, r;
    scanf("%lf %lf %lf", &a, &b, &c);
    s = (a+b+c)/2;
    S = sqrt(s*(s-a)*(s-b)*(s-c));
    // �ﰢ���� ���� S
    printf("%.10lf\n", S);
    // �������� �������� ���� R
    R = a*b*c/(4*S);
    printf("%.10lf\n", R);
    // �������� �������� ���� r
    r = 2*S/(a+b+c);
    printf("%.10lf\n", r);
    // �ܽɰ� ���� ������ ���� �Ÿ�
    if (a == b && b == c)
        printf("0\n");
    else
        printf("%.10lf\n", sqrt(R*(R-2*r)));
    // �ܽɿ��� �ﰢ���� �� ���� ���� �������� ������ ��
    printf("%.10lf", sqrt(R*R-a*a/4)+sqrt(R*R-b*b/4)+sqrt(R*R-c*c/4));
    return 0;
}