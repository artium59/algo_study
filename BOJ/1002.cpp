#include <iostream>
#include <cmath>

float max(float a, float b) { return a > b ? a : b; }
float max(float a, float b, float c) { return max(a, max(b, c)); }

int main() {
    int t, ans;
    float dist, p[6];

    scanf("%d", &t);
    while (t--) {
        for (int i = 0; i < 6; i++)
            scanf("%f", &p[i]);

        dist = sqrt((p[0]-p[3])*(p[0]-p[3]) + (p[1]-p[4])*(p[1]-p[4]));

        if (dist == 0) {
            if (p[2] == p[5]) ans = -1;
            else ans = 0;
        }
        else {
            if (dist == p[2]+p[5]) ans = 1;
            else {
                if (dist == p[2]-p[5] || dist == p[5]-p[2]) ans = 1;
                else {
                    if (max(p[2], p[5], dist) == p[2]) {
                        if (p[2] < p[5]+dist) ans = 2;
                        else ans = 0;
                    }
                    else if (max(p[2], p[5], dist) == p[5]) {
                        if (p[5] < p[2]+dist) ans = 2;
                        else ans = 0;
                    }
                    else {
                        if (dist < p[2]+p[5]) ans = 2;
                        else ans = 0;
                    }
                }
            }	
        }
	
        printf("%d\n", ans);
    }

    return 0;
}
