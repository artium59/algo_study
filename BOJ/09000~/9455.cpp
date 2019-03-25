#include <iostream>

bool box[100][100];

int main() {
    int tc, t, m, n, cnt, ans;

    scanf("%d", &tc);
    for (int h = 0; h < tc; h++) {
        ans = 0;
		
        scanf("%d %d", &m, &n);
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                scanf("%d", &t);
                box[i][j] = (t == 1);
            }
        }

        for (int j = 0; j < n; j++) {
            cnt = 0;
            for (int i = m; i > 0; i--) {
                if (!box[i-1][j]) cnt++;
                else ans += cnt;
            }
        }

        printf("%d\n", ans);
    }

    return 0;
}
