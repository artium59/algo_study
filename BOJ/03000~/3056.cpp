#include <iostream>
#include <cstring>

int n;
double t, missions[20][20], cache[1 << 20];

double max(double a, double b) {
    return a > b ? a : b;
}

double TSP(int cur, int visited) {
    if (visited == (1 << n) - 1) return 1;
    if (cur == n) return 1;
    
    double& ret = cache[visited];
    if (ret != 0) return ret;
    
    for (int i = 0; i < n; i++) {
        if (visited & (1 << i) || missions[cur][i] == 0) continue;
        ret = max(ret, TSP(cur+1, visited | (1 << i)) * missions[cur][i]);
    }
    
    return ret;
}

int main() {
    scanf("%d", &n);
    
    memset(cache, 0, sizeof(cache));
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%lf", &t);
            missions[i][j] = t/(double)100;
        }
    }
    
    printf("%.9lf", TSP(0, 0) * 100);
    
    return 0;
}
