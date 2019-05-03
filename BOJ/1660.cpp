#include <iostream>

inline int min(int a, int b) { return a < b ? a : b; }

int n, ans = 0, tetra[123], sum[122], dp[300001];

void Init() {
    for (int i = 0; i < 300001; i++)
        dp[i] = 987654321;
}

int Find(int cnt) {
    if (cnt <= 0) return 0;
    int& ret = dp[cnt];
    if (ret < 987654321) return ret;

    for (int i = 1; i <= n; i++) {
        if (cnt < sum[i]) break;
        ret = min(ret, 1+Find(cnt-sum[i]));
    }

    return ret;
}

int main() {
    tetra[0] = sum[0] = 0;
    for (int h = 1; h < 123; h++)
        tetra[h] = tetra[h-1] + h;
    for (int i = 1; i < 122; i++)
        sum[i] = sum[i-1] + tetra[i];
	
    scanf("%d", &n);

    Init();
    printf("%d", Find(n));

    return 0;
}
